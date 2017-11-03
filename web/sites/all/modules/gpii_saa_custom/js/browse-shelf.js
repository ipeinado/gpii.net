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
    $('.slides li').on('click', function() {
      window.location.href = $(this)
        .find('a[href]')
        .first()
        .attr('href');
    });
    // Call the event handler on #text
    $('.slides li').hover(function(){
      // add a class to children so we can style on hover/focus
      $(this).children().addClass("focused");
    },
      // Event two mouse out remove class
      function(){
      $(this).children().removeClass("focused");
    });

    $('.slides li a').focus(function() {
      $(this).closest('div').addClass('focused');
    }).blur(function() {
      $(this).closest('div').removeClass('focused');
    });
  });

}(jQuery));
