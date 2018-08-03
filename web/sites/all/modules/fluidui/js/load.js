/**
 * @file
 * Used to initialize the plugin when the page has finished loading.
 */

(function ($) {
  Drupal.behaviors.FLUID = {
    attach: function (context, settings) {

      var origin = Drupal.settings.basePath;
      var modulePath = Drupal.settings.modulePath;
      var libraryPath = Drupal.settings.libraryPath;

      var uio = fluid.uiOptions.prefsEditor(".flc-prefsEditor-separatedPanel", {
        terms: {
            "templatePrefix": origin + modulePath + "/html",
            "messagePrefix": origin + modulePath + "/messages/",
        },
        "tocTemplate": libraryPath + "/components/tableOfContents/html/TableOfContents.html",
        "ignoreForToC": {
          "overviewPanel": ".flc-overviewPanel"
        }
      });

      //for smaller screens ( < 480px ), display the toolbox in full width
      $(".fl-prefsEditor-buttons button").click(function (e) {
        var status = $(this).attr("aria-label");
        if (status == "Show Display Preferences"){
          if (window.innerWidth < 480){
            $(".flc-prefsEditor-separatedPanel").css("width", "100%");            
          }
        } else if (status == "Hide Display Preferences") {
          if (window.innerWidth < 480){
            $(".flc-prefsEditor-separatedPanel").css("width", "87%");            
          } else {
            $(".flc-prefsEditor-separatedPanel").css("width", "100%");            
          }
        }
      });

      $(window).resize(function() {
        if (window.innerWidth < 480){
          $(".flc-prefsEditor-separatedPanel").css("width", "87%");            
        } else {
          $(".flc-prefsEditor-separatedPanel").css("width", "100%");            
        }
      });
    }
  };
}(jQuery));
