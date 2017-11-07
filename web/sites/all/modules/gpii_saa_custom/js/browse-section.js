/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  $(document).ready(function(){
    $('#section li, #shelf li').on('click', function() {
      window.location.href = $(this)
        .find('a[href]')
        .first()
        .attr('href');
    });
    // Call the event handler on #text
    $('#section li, #shelf li').hover(function(){
      // add a class to children so we can style on hover/focus
      $(this).addClass("focused");
    },
      // Event two mouse out remove class
      function(){
      $(this).removeClass("focused");
    });

    $('#section li a, , #shelf li a').focus(function() {
      $(this).closest('li').addClass('focused');
    }).blur(function() {
      $(this).closest('li').removeClass('focused');
    });
  });

}(jQuery));
