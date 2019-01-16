(function ($) {
    'use strict';

    $(document).ready(function(){
        // expand the summary field by default
        $('.link-edit-summary:contains(Edit)').trigger('click');

        // disable the save button until required fields are set
        $('#product-node-form #edit-submit').prop('disabled', true).css('color', '#999999').css('cursor', 'not-allowed');

        $('#edit-log, #edit-category').on('keyup change', function() {
            var currentString = $('#edit-log').val();
            var revisionType = $('#edit-category').children('option:selected').val();
            if (currentString.length > 2 && revisionType != '' )  {
                //console.log(revisionType);
                $('#product-node-form #edit-submit').removeAttr("disabled").css('color', '#5a5a5a').css('cursor', 'pointer');
            }
            else {
                $('#product-node-form #edit-submit').prop('disabled', true).css('color', '#999999').css('cursor', 'not-allowed');
            }
        });
    });

    
}(jQuery));