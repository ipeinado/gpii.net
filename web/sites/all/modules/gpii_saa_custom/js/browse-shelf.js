/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  // flexslider config
  // Can also be used with $(document).ready()
  $(window).load(function() {
    $('.flexslider').flexslider({
      animation: "slide",
      animationLoop: false,
      animationSpeed: 2000,
      controlNav: false,
      itemWidth: 210,
      itemMargin: 0,
      minItems: 2,
      maxItems: 5,
      mousewheel: true,
      slideshow: false,
      useCSS: true
    });
  });

}(jQuery));
