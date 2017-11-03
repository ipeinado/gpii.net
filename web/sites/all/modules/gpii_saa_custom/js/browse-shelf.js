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
      animationSpeed: 800,
      controlNav: false,
      itemWidth: 210,
      itemMargin: 0,
      minItems: 2,
      maxItems: 5,
      mousewheel: false,
      slideshow: false,
      useCSS: true
    });
  });

  //increase the clicktarget on the flexslider items
  $(document).ready(function(){
    //console.log($('.slides > li'));
    $('.slides').on('click', function() {
      window.location.href = $(this)
        .find('a[href]')
        .first()
        .attr('href');

    });
  });

}(jQuery));
