(function($, Drupal) {
  "use strict";

  $(document).ready(function() {
    var uid = Drupal.settings.ul_save_and_updates.uid;
    var nid = Drupal.settings.ul_save_and_updates.nid;

    if ($("#notify-me-modal").length) {
      var modal = $("#notify-me-modal");
      modal.find(".modal-body, .notify-me-error").hide();

      if (uid == 0) {
        modal.find(".modal-body.notify-me-anon").show();
      } else {
        var statusCheck = $.get(`/saved-search/exists/${uid}/${nid}`);
        statusCheck.done(function(response) {
          if (response.success) {
            modal.find(".modal-body.notify-me-exists").show();
          } else {
            modal.find(".modal-body.notify-me-form").show();
          }
        });
      }
    } else if ($("#notify-me-modal-confirm").length) {
      var modal = $("#notify-me-modal-confirm");
      modal.find(".modal-body, .notify-me-error").hide();
      modal.find(".modal-body.notify-me-form").show();
    }

    $(".notify-me-button").click(function(event) {
      var button = $(this);
      var modalOption = button.data("modalOption");
      if (modalOption == "share") {
        $("#sharelink").val(document.location);
        $(".modal-body.notify-me-share").show();
        $(".modal-body.notify-me-form").hide();
      } else {
        $(".modal-body.notify-me-share").hide();
        $(".modal-body.notify-me-form").show();
      }

      $('input[name="search_name"]').attr(
        "value",
        new Date().toLocaleString().split(",")[0] +
          " - " +
          $("#edit-search-api-views-fulltext").attr("value")
      );
    });

    var saveForm = $("#notify-me-form-save");
    saveForm.submit(function(event) {
      event.preventDefault();

      if ($('input[name="search_url"]').length) {
        $('input[name="search_url"]').attr(
          "value",
          window.location.pathname + window.location.search
        );
      }

      var saving = $.post("/saved-search/save", saveForm.serialize());
      saving.done(function(response) {
        console.log(response);
        if (response.success) {
          modal.find(".modal-body.notify-me-form").hide();
          modal.find(".modal-body.notify-me-success").show();
        } else {
          modal.find(".notify-me-error").show();
        }
      });
    });

    // name edit

    $(".notify-me-name-wrapper").on("click", ".notify-me-name-edit", function(
      event
    ) {
      var id = $(this).data("id");
      var wrapper = $(this).parents(".notify-me-name-wrapper");
      var wrapperHTML = wrapper.html();
      var nameTEXT = wrapper.find(".notify-me-name").text();

      var idInput = $("<input>");
      idInput.attr("type", "hidden");
      idInput.attr("name", "id");
      idInput.attr("value", id);

      var nameInput = $("<input>");
      nameInput.attr("type", "text");
      nameInput.attr("name", "search_name");
      nameInput.attr("value", nameTEXT);

      var cancel = $("<button>Cancel</button>");
      cancel.click(function() {
        wrapper.html(wrapperHTML);
      });

      var submit = $("<button>Save</button>");
      submit.attr("type", "submit");

      var form = $("<form></form>");
      form.addClass("notify-me-form-edit");
      form.attr("data-callback", "notifyMeName");
      form.submit(editSubmit);

      form
        .append(idInput)
        .append(nameInput)
        .append(cancel)
        .append(submit);

      wrapper.html(form);
    });

    function notifyMeName(event, success) {
      var name, id, message;
      if (success) {
        name = $(event.target)
          .find('input[name="search_name"]')
          .val();
        id = $(event.target)
          .find('input[name="id"]')
          .attr("value");
        message = '<span class="name-saved-message"> Saved</span>';
      } else {
        name = $(event.target)
          .find('input[name="search_name"]')
          .attr("value");
        id = $(event.target)
          .find('input[name="id"]')
          .attr("value");
        message = '<span class="name-saved-message"> Error</span>';
      }

      var wrapper = $(event.target).parents(".notify-me-name-wrapper");
      wrapper.html(
        '<span class="notify-me-name">' +
          name +
          "</span>" +
          ' <button class="notify-me-name-edit btn btn-xs" data-id="' +
          id +
          '" style="cursor: pointer;">edit</button>)' +
          message +
          "</span>"
      );

      setTimeout(
        function(wrapper) {
          wrapper.find(".name-saved-message").remove();
        },
        5000,
        wrapper
      );
    }

    // checkboxes
    $(".notify-me-new-entries, .notify-me-major-changes").change(function(
      event
    ) {
      $(this.form).trigger("submit");
      $(this)
        .parent()
        .find("label")
        .append('<span class="label-text">Saving...</span>');
    });

    function notifyMeCheckbox(event, success) {
      var label = $(event.target).find("label");
      label.children(".label-text").remove();
      if (success) {
        label.append('<span class="label-text">Saved</span>');
      } else {
        label.append('<span class="label-text">Error Saving</span>');
      }
      setTimeout(
        function(label) {
          label.children(".label-text").remove();
        },
        5000,
        label
      );
    }

    var editForm = $("#notify-me-form-edit, .notify-me-form-edit");
    editForm.submit(editSubmit);

    function editSubmit(event) {
      event.preventDefault();
      var callback = $(this).data("callback");
      var editing = $.post("/saved-search/edit", $(this).serialize());
      editing.done(function(response) {
        eval(callback + "(event, response.success)");
      });
    }

    $(".notify-me-button-remove").click(function(event) {
      $('#notify-me-form-delete input[name="id"]').attr(
        "value",
        event.target.dataset.id
      );
    });

    var deleteForm = $("#notify-me-form-delete");
    deleteForm.submit(function(event) {
      event.preventDefault();
      var deleting = $.post("/saved-search/delete", $(this).serialize());
      deleting.done(function(response) {
        console.log(response);
        if (response.success) {
          $("#notify-me-modal-confirm").modal("hide");
          $(
            "#saved-search-" + deleteForm.find('input[name="id"]').attr("value")
          ).remove();
        } else {
          modal.find(".notify-me-error").show();
        }
      });
    });

    // share link clipboard functionality
    $(".share-link-copy").click(function(event) {
      event.preventDefault();
      $("#sharelink").select();
      try {
        document.execCommand("copy");
        if ($(".copy-status").length < 1) {
          $(this)
            .parent()
            .append($('<span class="copy-status badge badge-success">Copied!</span>'));
        }
        $(".copy-status").text("Copied");
      } catch (e) {
        if (!$(".copy-status")) {
          $(this)
            .parent()
            .append($('<span class="copy-status badge badge-success">Copied!</span>'));
        }
        $(".copy-status").text("Copied");
      }

      setTimeout(function() {
        $(".copy-status").remove();
      }, 5000);
    });
  });
})(jQuery, Drupal);
