(function($, Drupal) {
  "use strict";

  Drupal.behaviors.ul_save_and_updates = {
    viewHandler: function() {
      if ($("#notify-me-modal").length) {
        var modal = $("#notify-me-modal");
        // initialize the modal by hiding everything.
        modal.find(".modal-body, #notify-me-submit-failed").hide();

        if (Drupal.behaviors.ul_save_and_updates.modalOption == "share") {
          Drupal.behaviors.ul_save_and_updates.setShareView(modal);
        } else {
          Drupal.behaviors.ul_save_and_updates.setFormView(modal);
        }
      } else if ($("#notify-me-modal-confirm").length) {
        var modal = $("#notify-me-modal-confirm");
        modal.find(".modal-body, #notify-me-submit-failed").hide();
        modal.find(".modal-body.notify-me-form").show();
      }
    },

    setShareView: function(modal) {
      // start fresh
      modal.find(".modal-body").hide();

      // if angular has not set the share link value then set it
      if (!$("#sharelink").val()) {
        $("#sharelink").val(document.location);
      }
      modal.find(".modal-body.notify-me-share").show();
    },

    setFormView: function(modal) {
      var uid = Drupal.settings.ul_save_and_updates.uid;
      var nid = Drupal.settings.ul_save_and_updates.nid;

      // start fresh
      modal.find(".modal-body, #notify-me-submit-failed").hide();

      if (uid == 0) {
        modal.find(".modal-body.notify-me-anon").show();
      } else {
        var statusCheck = $.get(`/saved-search/exists/${uid}/${nid}`);
        statusCheck.done(function(response) {
          if (response.success) {
            modal.find(".modal-body.notify-me-exists").show();
          } else {
            // if modal option is search conditionally show form by checking for query filters
            if (Drupal.behaviors.ul_save_and_updates.modalOption == "search") {
              // set search_url if angular hasn't already
              if (!$("#search-url").val()) {
                $("#search-url").val(window.location);
              }
              if (checkQueryForFilters($("#search-url").val())) {
                var query = getQueryArray($("#search-url").val());
                // autofill search name to default
                var searchTerm =
                  query["query"] || query["search_api_views_fulltext"];
                var autofill = new Date().toLocaleString().split(",")[0];
                autofill += searchTerm ? " - " + searchTerm : "";
                $("#search-name").val(autofill);

                modal.find(".modal-body.notify-me-form").show();
              } else {
                modal.find(".modal-body.notify-me-no-filters").show();
              }
            } else {
              modal.find(".modal-body.notify-me-form").show();
            }
          }
        });
      }

      // check for search values to avoid saving notifications on every product in the database
      function checkQueryForFilters(url) {
        var query = getQueryArray(url);

        if (
          query.hasOwnProperty("query") ||
          query.hasOwnProperty("troubles") ||
          query.hasOwnProperty("os") ||
          query.hasOwnProperty("product_cateogry") ||
          query.hasOwnProperty("f%5B0%5D") ||
          query.hasOwnProperty("f[0]") ||
          query.hasOwnProperty("search_api_views_fulltext")
        ) {
          return true;
        } else {
          return false;
        }
      }

      function getQueryArray(url) {
        var query = {};
        url
          .split("?")[1]
          .split("&")
          .forEach(function(item) {
            query[item.split("=")[0]] = item.split("=")[1];
          });
        return query;
      }
    },

    attach: function(context, settings) {
      if ($("#notify-me-modal").length) {
        // initialize the modal by hiding everything.
        var modal = $("#notify-me-modal");
      }

      // This call of the viewHandler() is for Angular search pages as the attach function
      // is manually called when Angular adds the modal to the page.
      Drupal.behaviors.ul_save_and_updates.viewHandler();

      var saveForm = $("#notify-me-form-save");
      saveForm.submit(function(event) {
        event.preventDefault();
        var saving = $.post("/saved-search/save", saveForm.serialize());
        saving.done(function(response) {
          if (response.success) {
            modal.find(".modal-body.notify-me-form").hide();
            modal.find(".modal-body.notify-me-success").show();
          } else {
            modal.find("#notify-me-submit-failed").show();
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

        var nameLabel = $(
          '<label for="newName"><span class="sr-only">Search Name</span></label>'
        );

        var nameInput = $("<input>");
        nameInput.attr("type", "text");
        nameInput.attr("id", "newName");
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
          .append(nameLabel)
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
          message =
            ' <span class="name-saved-message badge badge-success" aria-live="polite">Saved</span>';
        } else {
          name = $(event.target)
            .find('input[name="search_name"]')
            .attr("value");
          id = $(event.target)
            .find('input[name="id"]')
            .attr("value");
          message =
            ' <span class="name-saved-message badge badge-success" aria-live="polite">Error</span>';
        }

        var wrapper = $(event.target).parents(".notify-me-name-wrapper");
        wrapper.html(
          '<span class="notify-me-name">' +
            name +
            "</span>" +
            ' <button class="notify-me-name-edit btn-default btn btn-xs" data-id="' +
            id +
            '" style="cursor: pointer;">edit</button>' +
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
          label.append(
            '<span class="label-text badge badge-success" aria-live="polite">Saved</span>'
          );
        } else {
          label.append(
            '<span class="label-text badge badge-danger" aria-live="polite">Error Saving</span>'
          );
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
          // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/eval#Never_use_eval!
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
          if (response.success) {
            $("#notify-me-modal-confirm").modal("hide");
            $(
              "#saved-search-" +
                deleteForm.find('input[name="id"]').attr("value")
            ).remove();
          } else {
            modal.find("#notify-me-submit-failed").show();
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
              .append(
                $(
                  '<span class="copy-status badge badge-success" aria-live="polite">Copied!</span>'
                )
              );
          }
          $(".copy-status").text("Copied!");
        } catch (e) {
          if (!$(".copy-status")) {
            $(this)
              .parent()
              .append(
                $(
                  '<span class="copy-status badge badge-success" aria-live="polite">Copied!</span>'
                )
              );
          }
          $(".copy-status").text("Copied!");
        }

        setTimeout(function() {
          $(".copy-status").remove();
        }, 6000);
      });
    }
  };

  $(document).ready(function() {
    $(".notify-me-button").click(function(event) {
      Drupal.behaviors.ul_save_and_updates.modalOption = $(this).data(
        "modalOption"
      );

      // This call of the viewHandler() is for Non Angular search pages.
      Drupal.behaviors.ul_save_and_updates.viewHandler();
    });
  });
})(jQuery, Drupal);
