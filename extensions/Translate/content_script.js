var rr=0,calls=0;
const urls=["https://translate.argosopentech.com/translate","https://translate.terraprint.co/translate"];
const messageContainer = document.querySelector(".chat-scrollable-area__message-container");
const identifier = "&%&$@";

const observer = new MutationObserver((mutationsList) => {
  for (const mutation of mutationsList) {
    if (mutation.type === "childList") {
      const addedNodes = Array.from(mutation.addedNodes);
        // Handle added nodes
        addedNodes.forEach((node, index) => {
          if (node && node.querySelectorAll) {
            // Check if the added node or its children have the desired text fragment
            const textFragments = node.querySelectorAll(".text-fragment[data-a-target='chat-message-text']");
            var textFrags=[];
            for (let i = 0; i < textFragments.length; i++) {
              textFrags.push(textFragments[i]);
            }
            translateText(textFrags);
          }
        });
    }
  }
});

observer.observe(messageContainer, { childList: true, subtree: true });
function buildString(textFrags){
  var string="";
  for (var i=0; i<textFrags.length; i++){
    string+=textFrags[i].textContent+identifier;
  }
  return string;
}
function extractTextFrags(string) {
  string = string.substring(0, string.length+1 - identifier.length); 
  return string.split(identifier);
}
function translationExists(translationKey){
  const storedTranslation = localStorage.getItem(translationKey);
  if (storedTranslation) {
    return storedTranslation;
  }
  else{
    return 1!==1;
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
  for (let i = 0; i < textFrags.length; i++) {
    const translationKey = sourceLanguage+2+targetLanguage+`:translation_${textFrags[i].textContent}`;
    const storedTranslation = translationExists(translationKey);
    if (storedTranslation) {
      textFrags[i].textContent = storedTranslation;
      console.log("found:",storedTranslation);
      textFrags.splice(i, 1);
      i--;
      }
    }
    return textFrags;
}

async function translateText(textFrags) {
  if (!textFrags[0]) {
    return;
  }
  console.log(textFrags[0].textContent);

  // Check if the translation exists in local storage
  const { sourceLanguage, targetLanguage } = getLang();
  textFrags = removeTranslated(textFrags, sourceLanguage, targetLanguage);

  const str = buildString(textFrags);
  // Your code here
  if (str.length <= 0) {
    return;
  }

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
    const translationKey = sourceLanguage + 2 + targetLanguage + `:translation_${translatedTextFrags[i].textContent}`;
    if (translatedTextFrags[i].length > 1)
      textFrags[i].textContent = translatedTextFrags[i];
    localStorage.setItem(translationKey, translatedText);
    console.log(calls++,translatedTextFrags[i]);
  }
}