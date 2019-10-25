(function($, Drupal) {
  'use strict';

  $(document).ready(function() {
    var uid = Drupal.settings.ul_save_and_updates.uid;
    var nid = Drupal.settings.ul_save_and_updates.nid;

    if ($('#notify-me-modal').length) {
      var modal = $('#notify-me-modal');
      modal.find('.modal-body, .notify-me-error').hide();

      if (uid == 0) {
        modal.find('.modal-body.notify-me-anon').show();
      } else {
        var statusCheck = $.get(`/saved-search/exists/${uid}/${nid}`);
        statusCheck.done(function(response) {
          if (response.success) {
            modal.find('.modal-body.notify-me-exists').show();
          } else {
            modal.find('.modal-body.notify-me-form').show();
          }
        });
      }
    } else if ($('#notify-me-modal-confirm').length) {
      var modal = $('#notify-me-modal-confirm');
      modal.find('.modal-body, .notify-me-error').hide();
      modal.find('.modal-body.notify-me-form').show();
    }

    var saveForm = $('#notify-me-form-save');
    saveForm.submit(function(event) {
      event.preventDefault();
      var saving = $.post('/saved-search/save', saveForm.serialize());
      saving.done(function(response) {
        if (response.success) {
          modal.find('.modal-body.notify-me-form').hide();
          modal.find('.modal-body.notify-me-success').show();
        } else {
          modal.find('.notify-me-error').show();
        }
      });
    });

    $('.notify-me-new-entries, .notify-me-major-changes').change(function(event) {
      $(this.form).trigger('submit');
      $(this)
        .parent()
        .find('label')
        .append('<span class="label-text">Saving...</span>');
    });

    var editForm = $('#notify-me-form-edit, .notify-me-form-edit');
    editForm.submit(function(event) {
      event.preventDefault();
      var label = $(this).find('label');
      var editing = $.post('/saved-search/edit', $(this).serialize());
      editing.done(function(response) {
        if (response.success) {
          label.children('.label-text').remove();
          label.append('<span class="label-text">Saved</span>');
          setTimeout(
            function(label) {
              label.children('.label-text').remove();
            },
            5000,
            label
          );
        } else {
          label.children('.label-text').remove();
          label.append('<span class="label-text">Error Saving</span>');
          setTimeout(
            function(label) {
              label.children('.label-text').remove();
            },
            5000,
            label
          );
        }
      });
    });

    $('.notify-me-button-remove').click(function(event) {
      $('#notify-me-form-delete input[name="id"]').attr('value', event.target.dataset.id);
    });

    var deleteForm = $('#notify-me-form-delete');
    deleteForm.submit(function(event) {
      event.preventDefault();
      var deleting = $.post('/saved-search/delete', $(this).serialize());
      deleting.done(function(response) {
        console.log(response);
        if (response.success) {
          $('#notify-me-modal-confirm').modal('hide');
          $('#saved-search-' + deleteForm.find('input[name="id"]').attr('value')).remove();
        } else {
          modal.find('.notify-me-error').show();
        }
      });
    });
  });
})(jQuery, Drupal);
