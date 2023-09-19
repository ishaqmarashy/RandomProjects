var rr=0,calls=0;
var translatedTextArray = [];
const urls=["https://translate.argosopentech.com/translate","https://translate.terraprint.co/translate"];
const messageContainer = document.querySelector(".chat-scrollable-area__message-container");
const identifier = "‽";

const observer = new MutationObserver((mutationsList) => {
  for (const mutation of mutationsList) {
    if (mutation.type === "childList") {
      const addedNodes = Array.from(mutation.addedNodes);
        // Handle added nodes
        addedNodes.forEach((node, index) => {
          if (node && node.querySelectorAll) {
            // Check if the added node or its children have the desired text fragment
            const textFragments = node.querySelectorAll(".text-fragment[data-a-target='chat-message-text']");
            for (let i = 0; i < textFragments.length; i++) {
              translatedTextArray.push(textFragments[i]);
            }
          }
        });
    }
  }
});
observer.observe(messageContainer, { childList: true, subtree: true });

function start(){
  setTimeout(() => {
    if(translatedTextArray.length>0){
      const copy = translatedTextArray.slice(); // send a copy
      translatedTextArray.length = 0; // empty the original array
      translateText(copy); // translate the copy
    }
    start();
  }, 5000);
}
start();

function buildString(textFrags){
  var string="";
  for (var i=0; i<textFrags.length; i++){
    if(i==(textFrags.length-1)){
      string+=textFrags[i].textContent
    }
    else{
      string+=textFrags[i].textContent+identifier;
    }
  }
  return string;
}
function extractTextFrags(string) {
  return string.split(identifier);
}
function translationExists(translationKey){
  const storedTranslation = localStorage.getItem(translationKey);
  if (storedTranslation) {
    return storedTranslation;
  }
  else{
    return false;
  }
}
function getLang(){
  var sourceLanguage = localStorage.getItem("translation_sourceLanguage$");
  var targetLanguage = localStorage.getItem("translation_targetLanguage$");
  if (!sourceLanguage) {
    sourceLanguage="auto";
    localStorage.setItem("translation_sourceLanguage$",sourceLanguage);
  }
  if (!targetLanguage) {
    targetLanguage="en";
    localStorage.setItem("translation_targetLanguage$",targetLanguage);
  }
  return {sourceLanguage,targetLanguage};
}
function removeTranslated(textFrags,sourceLanguage,targetLanguage){
  for (let i = 0; i < textFrags.length&&i>=0; i++) {
    const translationKey = sourceLanguage + 2 + targetLanguage + `:translation_${textFrags[i].textContent}`;
    const storedTranslation = translationExists(translationKey);
    if (storedTranslation) {
      textFrags[i].textContent = storedTranslation;
      textFrags.splice(i, 1);
      i--;
      }
    }
    return textFrags;
}

async function translateText(textFrags) {
  var disabled=localStorage.getItem("TranslatorDisabled_$");
  const { sourceLanguage, targetLanguage } = getLang();
  console.info("Before:",!textFrags[0]||disabled!=null,textFrags);
  // Check if the translation exists in local storage and remove the ones found
  // This means the string builder will only take the ones not found
  // in the local storage and send them for translation
  textFrags = removeTranslated(textFrags, sourceLanguage, targetLanguage);
  console.info("After:",!textFrags[0]||disabled!=null,textFrags);
  if (!textFrags[0]||disabled!=null) {return;}

  
  // Sanitize the text fragments for multiple languages
  for (let i = 0; i < textFrags.length; i++) {
    textFrags[i].textContent = textFrags[i].textContent.trim();
  }
  // String builder / instead of sending a request every message
  // Concatinate the strings and place seperator between them similar to CSVs
  const str = buildString(textFrags);
  // String builder will return an emptry string if theresnothing to build from
  // I could technically check before this like but its redundent
  if (str.length <= 0) {return;}

  const response = await fetch(urls[rr], {
    method: "POST",
    body: JSON.stringify({
      q: str,
      source: sourceLanguage,
      target: targetLanguage
    }),
    headers: { "Content-Type": "application/json" }
  });

  rr = (1 + rr) % urls.length;
  const data = await response.json();
  const translatedText = data.translatedText;
  var translatedTextFrags = extractTextFrags(translatedText);
  for (var i = 0; i < textFrags.length; i++) {
    const translationKey = sourceLanguage + 2 + targetLanguage + `:translation_${textFrags[i].textContent}`;
    if (translatedTextFrags[i] && translatedTextFrags[i].length > 1){
      textFrags[i].textContent = translatedTextFrags[i];
    }
      localStorage.setItem(translationKey, textFrags[i].textContent);
  }
}