/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  // Tag the body when viewed in IE to fix some style issues.
  $(document).ready(function(){
    if (navigator.userAgent.match(/MSIE/g)
        || navigator.userAgent.match(/Trident\/7.0/g)) {
      $(document.body).addClass('ie');
    }
  });

  // Set up ARIA roles where necessary.
  $(document).ready(function() {
    $('.region-branding').attr('role', 'banner');
    $('.region-content').attr('role', 'main');
    $('.footer').attr('role', 'contentinfo');
    $('.node').attr('role', 'article');
    $('.block').attr('role', 'complementary');
    $('#search-form').attr('role', 'search');
  });

  // Dynamically adjust the breakpoints based on font changes to the <html>
  // element from Fluid UI.
  $(document).ready(function(){
    var $html = $('html'),
        baseFontSize = 1,
        breakpoints = {};

    // The base font size and breakpoints (indices) must match the stylesheet.
    // The values represent the ratios at which the screen size should be forced
    // to the mobile version.
    baseFontSize = 14;
    breakpoints[768] = 1.2;
    breakpoints[992] = 1.4;
    breakpoints[1200] = 1.6;

    var callback = function() {
      var fontSize = parseFloat($html.css('font-size')),
          browserWidth = $html.width(),
          ratio = (fontSize / baseFontSize).toFixed(1),
          forceMobileLayout = false;

      for (var i in breakpoints) {
        if (browserWidth >= i) {
          forceMobileLayout = ratio >= breakpoints[i];
        } else {
          break;
        }
      }

      $html[forceMobileLayout ? 'addClass' : 'removeClass']('force-mobile-layout');
    };

    callback();
    $(window).resize(callback);
    $html.watch({properties: 'font-size', callback: callback});
  });

  // Add functionality for the tab that displays the translation options. It
  // mimics the FluidUI component and also makes the two work well together at
  // the top of the page.
  $(document).ready(function(){
    var $googleTranslate = $('#block-google-translator-active-languages'),
        $toggleContainer = $('#gpii-translate-toggle_container'),
        $toggleButton = $('#gpii-translate-toggle_button'),
        $fluidUiPanel = $('.fl-prefsEditor-separatedPanel'),
        duration = 400;

    $toggleButton.click(function(){
      var visible = $googleTranslate.is(':visible');

      setTimeout(function(){ $fluidUiPanel.toggle(); }, (visible ? duration : 0));
      $(this).text((visible ? '+  Translate To...' : '- Hide'));
      $googleTranslate.slideToggle({
        duration: duration,
        progress: function(){ $toggleContainer.css('top', $googleTranslate.outerHeight()+'px'); },
        complete: function(){
          $('.goog-te-combo').focus();
          if (visible) {
            $toggleContainer.css('top', '0px');
          }
        }
      });
    });

    $(window).resize(function(){
      var offset = $googleTranslate.is(':visible') ? $googleTranslate.outerHeight() : 0;
      $toggleContainer.css('top', offset+'px');
    });

    setTimeout(function(){
      $('.goog-te-combo').change(function(){ $toggleButton.click(); });
    }, 1500);

    $('#show-hide').click(function(){
      var visible = $(this).text().match(/^\s*\-/);

      setTimeout(function(){ $toggleContainer.toggle(); }, (visible ? duration : 0));

      // Temporarily modify the width of the FluidUI panel so that it doesn't
      // interfere with other elements at the top of the page, e.g., the
      // translation tab.
      if (!visible) {
        $fluidUiPanel.css('width', '100%');
      } else {
        setTimeout(function(){ $fluidUiPanel.css('width', 'auto'); }, 1000);
      }
      console.log(document.getElementById('iframe-focus'));
      if (document.getElementById('iframe-focus')) {
        $('#iframe-focus').focus();
      } else { 
        $('.flc-prefsEditor-iframe').before('<a id="iframe-focus" href></a>');
        $('#iframe-focus').focus();
      }
    });
  });

}(jQuery));

// setTimeout(function () {
//   // google translate selector
//   var translate = document.querySelector('.goog-te-combo');
//   var languages = [ 'af', 'sq', 'ar', 'be', 'bg', 'ca', 'zh-CN', 'zh-TW', 'hr', 'cs', 'da', 'nl', 'eo', 'et', 'tl', 'fi', 'fr', 'gl', 'de', 'el', 'ht', 'iw', 'hi', 'hu', 'is', 'id', 'ga', 'it', 'ja', 'ko', 'lv', 'lt', 'mk', 'ms', 'mt', 'no', 'fa', 'pl', 'pt', 'ro', 'ru', 'sr', 'sk', 'sl', 'es', 'sw', 'sv', 'th', 'tr', 'uk', 'vi', 'cy', 'yi'];
//   // add event listener
//   translate.addEventListener('change', function () {
//     // split path into segments
//     var href = window.location.href.split('/');
//     // new language
//     var newLang = translate.value;
//     var oldLang = href[3];
//     if (languages.indexOf(oldLang) > -1) {
//       if (newLang !== 'en') {
//         href.splice(3, 1, newLang);
//       } else {
//         href.splice(3, 1);
//       }
//     } else {
//       href.splice(3, 0, newLang);
//     }
//     // redirect!
//     window.location.href = href.join('/');
//   });
// }, 2500);
