(function($) {
  'use strict';

  $(document).ready(function() {
    var status = $('#edit-field-status-und');
    var dis_msg_wrapper = $('#edit-field-discontinued-message');
    var dis_msg_none = $('#edit-field-discontinued-message-und-none');

    setDiscontinuedDisplay();

    status.on('change', function() {
      setDiscontinuedDisplay();
      if (status.val() != 2) {
        dis_msg_none.prop('checked', true);
      }
    });

    dis_msg_none.on('click', function() {
      status.val(1);
      setDiscontinuedDisplay();
      alert(
        'By setting Discontinued Message to none the status has been set to active. If it should be a different status, please set it now.'
      );
    });

    function setDiscontinuedDisplay() {
      if (status.val() == 2) {
        dis_msg_wrapper.css('display', 'initial');
      } else {
        dis_msg_wrapper.css('display', 'none');
      }
    }
  });
})(jQuery);
