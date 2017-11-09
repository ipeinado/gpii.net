/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  $(document).ready(function(){
    $('.browse-stores').on('click', function() {
      window.location.href = $(this)
        .find('a[href]')
        .first()
        .attr('href');
    });
    // Call the event handler on #text
    $('.browse-stores').hover(function(){
      // add a class to children so we can style on hover/focus
      $(this).addClass("focused");
    },
      // Event two mouse out remove class
      function(){
      $(this).removeClass("focused");
    });

    $('.browse-stores a').focus(function() {
      $(this).parent('div').addClass('focused');
    }).blur(function() {
      $(this).parent('div').removeClass('focused');
    });
  });

}(jQuery));
