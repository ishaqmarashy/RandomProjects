// content_script.js

function sendUrlsToBackground(urls) {
  // Send the URLs to the background script
  browser.runtime.sendMessage({ urls });
}

// Add a keyup event listener to the document
window.addEventListener("keyup", function (event) {
  var expression = /[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)?/gi;
  var regex = new RegExp(expression);
  var t = window.getSelection().toString();
  var matches = t.match(regex);

  // Check if Shift key is pressed and Enter is pressed
  if (event.shiftKey && event.key === "Enter" && matches) {
    sendUrlsToBackground(matches);
  }
});
