/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  // Tag the body when viewed in IE to fix some style issues.
  $(document).ready(function(){
    $('.panel')
    .on('click', function() {
      window.location.href = $(this)
        .find('.content a[href]')
        .first()
        .attr('href');
    });
    $('.panel').children().focus(function() {
    $(this).parent().css("background-color", "orange");
    }).blur(function() {
        $(this).parent().css("background-color","yellow");
    });
  });

}(jQuery));
