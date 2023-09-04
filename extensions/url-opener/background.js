// background.js

// Listen for messages from the content script
browser.runtime.onMessage.addListener(function (message) {
  if (message.urls) {
    message.urls.forEach(function (url) {
      // Check if the URL has a protocol; if not, add "http://"
      if (!url.startsWith("http://") && !url.startsWith("https://")) {
        url = "http://" + url;
      }
      browser.tabs.create({ url: url, active: false });
    });
  }
});