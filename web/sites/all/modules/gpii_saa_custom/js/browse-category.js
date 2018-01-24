/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  $(document).ready(function(){
    // make the store maps responsive image maps
    $('img[usemap]').rwdImageMaps();


    // make the store map divs clickable and styleable on hover
    //

    $('#storemap div.group div').on('click', function() {
      window.location.href = $(this)
        .find('a[href]')
        .first()
        .attr('href');
    });
    // Call the event handler on #text
    $('#storemap div.group div').hover(function(){
      // add a class to children so we can style on hover/focus
      $(this).addClass("focused");
    },
      // Event two mouse out remove class
      function(){
      $(this).removeClass("focused");
    });

    $('p.term a').focus(function() {
      $(this).closest('div').addClass('focused');
    }).blur(function() {
      $(this).closest('div').removeClass('focused');
    });
  });

}(jQuery));
