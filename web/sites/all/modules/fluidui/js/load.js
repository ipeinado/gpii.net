/**
 * @file
 * Used to initialize the plugin when the page has finished loading.
 * Customized based on the README instructions to allow for i18n
 */

(function ($) {
  Drupal.behaviors.FLUID = {
    attach: function (context, settings) {

      var origin = Drupal.settings.basePath;
      var modulePath = Drupal.settings.modulePath;
      var libraryPath = Drupal.settings.libraryPath;


      var path = window.location.pathname;
      console.log(path);

      if (path.lastIndexOf('/el/', 0) === 0) {
        fluid.uiOptions.prefsEditor(".flc-prefsEditor-separatedPanel", {
          "templatePrefix": libraryPath + "/framework/preferences/html/",
          "messagePrefix": origin + modulePath + "/messages/el/",
          "tocTemplate": libraryPath + "/components/tableOfContents/html/TableOfContentsEL.html" // @@ figure out why this doesn't seem to work
        });
      }
      else {
        fluid.uiOptions.prefsEditor(".flc-prefsEditor-separatedPanel", {
          "templatePrefix": libraryPath + "/framework/preferences/html/",
          "messagePrefix": origin + modulePath + "/messages/en/",
          "tocTemplate": libraryPath + "/components/tableOfContents/html/TableOfContents.html"
        });
      }


      }
  };
}(jQuery));
