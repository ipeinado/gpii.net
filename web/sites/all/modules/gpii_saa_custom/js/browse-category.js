/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  $(document).ready(function(){
    // make the store maps responsive image maps
    $('img[usemap]').rwdImageMaps();
  });

}(jQuery));
