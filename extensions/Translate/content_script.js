var rr=0;
const urls=['https://translate.argosopentech.com/translate','https://translate.terraprint.co/translate'];
const messageContainer = document.querySelector('.chat-scrollable-area__message-container');

const observer = new MutationObserver((mutationsList) => {
  for (const mutation of mutationsList) {
    if (mutation.type === 'childList') {
      const addedNodes = Array.from(mutation.addedNodes);

      // Handle added nodes
      addedNodes.forEach(node => {
        if(node&& node.querySelectorAll){
          // Check if the added node or its children have the desired text fragment
          const textFragments = node.querySelectorAll('.text-fragment[data-a-target="chat-message-text"]');
          textFragments.forEach(textFragment => {
            const text = textFragment.textContent.trim();
            if (text.length > 1) {
              translateText(text, textFragment);
            }
          });
        }
      });
    }
  }
});

observer.observe(messageContainer, { childList: true, subtree: true });

async function translateText(text, textFragment) {
  // Check if the translation exists in local storage
  var sourceLanguage = localStorage.getItem('translation_sourceLanguage$');
  var targetLanguage = localStorage.getItem('translation_targetLanguage$');
  const translationKey = `translation_${text}`;
  const storedTranslation = localStorage.getItem(translationKey);
  if (!sourceLanguage) 
      sourceLanguage="auto";
  if (!targetLanguage) 
      targetLanguage="en";
  if (storedTranslation) {
    // Use the stored translation
    console.log(sourceLanguage,targetLanguage,'Stored Translation:', storedTranslation); // Log the translated text
    textFragment.textContent = storedTranslation;
    return;
  }
  const response = await fetch(urls[rr], {
    method: "POST",
    body: JSON.stringify({
      q: text,
      source: sourceLanguage,
      target: targetLanguage
    }),
    headers: { "Content-Type": "application/json" }
  });
  rr=(1+rr)%urls.length;
  const data = await response.json();
  const translatedText = data.translatedText;

  console.log(sourceLanguage,targetLanguage,'Translation:', translatedText); // Log the translated text

  // Update the DOM with the translated text
  textFragment.textContent = translatedText;

  // Store the translation in local storage
  localStorage.setItem(translationKey, translatedText);
}