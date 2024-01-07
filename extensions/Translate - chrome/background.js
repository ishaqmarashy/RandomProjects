// Add an event listener to the browser action icon
chrome.action.onClicked.addListener(handleIconClick);

function handleIconClick() {
  var disabled = localStorage.getItem("TranslatorDisabled_$");
  if (disabled == null) {
    // Disable the addon
    localStorage.setItem("TranslatorDisabled_$", "true");
    chrome.action.setIcon({
      path: {
        "16": "icons/icon16D.png",
        "32": "icons/icon32D.png",
        "48": "icons/icon48D.png",
        "64": "icons/icon64D.png",
        "128": "icons/icon128D.png"
      }
    });
  } else {
    // Enable the addon
    localStorage.removeItem("TranslatorDisabled_$");
    chrome.action.setIcon({
      path: {
        "16": "icons/icon16.png",
        "32": "icons/icon32.png",
        "48": "icons/icon48.png",
        "64": "icons/icon64.png",
        "128": "icons/icon128.png"
      }
    });
  }
}
