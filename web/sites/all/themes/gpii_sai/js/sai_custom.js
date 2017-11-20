/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  // Tag the body when viewed in IE to fix some style issues.
  $(document).ready(function(){
    $('.highlighted .panel')
    .on('click', function() {
      window.location.href = $(this)
        .find('.content a[href]')
        .first()
        .attr('href');
    });
  });

}(jQuery));
