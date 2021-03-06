<div id="save-and-notify" style="display: flex; justify-content: flex-end; margin-top: 10px;">
  <button
    id="notify-me-button-share"
    style="margin-right: 10px;"
    type="button"
    class="btn btn-primary notify-me-button"
    data-toggle="modal"
    data-target="#notify-me-modal"
    data-modal-option="share"
    aria-label="Share this Search"
  >
    <span class="fa fa-link"></span>
  </button>
  <button
    id="notify-me-button"
    type="button"
    class="btn btn-primary notify-me-button"
    data-toggle="modal"
    data-target="#notify-me-modal"
    data-modal-option="search"
    aria-label="Save this Search"
  >
    <span aria-hidden="true" class="fa fa-envelope"></span>
  </button>
</div>

<div id="notify-me-modal" class="modal fade" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
        <h3 class="modal-title">
          Search Actions
        </h3>
      </div>
      <div class="modal-body notify-me-share">
        <h4>Share this search</h4>
        <p>
          Click on the icon below to copy the sharable link to your clipboard. Visiting this link will run a search with
          the currently selected keywords and filters applied.
        </p>
        <div class="form-inline">
          <div class="form-group" id="sharelink-group">
            <input
              id="sharelink"
              class="form-control"
              aria-invalid="false"
            />
          </div>
          <button class="share-link-copy btn btn-default" aria-label="Copy link to clipboard">
            <span class="fa fa-clipboard" aria-hidden="true"></span>
          </button>
        </div>
      </div>
      <div class="modal-body notify-me-anon">
        <h4>Save this search</h4>
        <p>
          If you want to save searches, so you can run them again easily, or get email about new products you will need
          to sign up for an account with the Unified Listing.
        </p>
        <p>
          With an account, you can get email updates on specific products, categories of products, companies' products,
          and even custom searches for products.
        </p>
        <p><a href="/user/login">Log in now</a> or <a href="/user/register">create an account</a>.</p>
      </div>
      <div class="modal-body notify-me-success">
      <p>
          You have successfully subscribed to email notifications for this search. To manage your subscriptions, visit
          the
          <a href="/user/<?= $GLOBALS['user']->uid ?>/email-notifications">Email Notifications</a> tab on your user profile page.
        </p>
      </div>
      <div class="modal-body notify-me-no-filters">
        <div id="notify-me-no-filters-error" class="alert alert-danger notify-me-error" role="alert">
          Your search must include at least one search term or category filter.
        </div>
      </div>
      <div class="modal-body notify-me-form">
        <h4>Save this search</h4>
        <form id="notify-me-form-save">
          <input type="hidden" name="uid" value="<?= $GLOBALS['user']->uid ?>" />
          <input type="hidden" name="search_type" value="classic_search" />
          <input id="search-url" type="hidden" name="search_url" />

          <div id="notify-me-submit-failed" class="alert alert-danger alert-dismissible notify-me-error" role="alert">
            Something went wrong. Please try again later.
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </button>
          </div>
          <div class="form-group">
            <label for="searchName">Give this search a name (optional)</label>
            <input type="text" class="form-control" id="search-name" name="search_name" />
          </div>

          <p>Notify me with the following types of search result changes:</p>
          <div class="checkbox">
            <label for="notify-me-new-entries">
              <input id="notify-me-new-entries" type="checkbox" name="new_entries" checked /> New entries to this search
            </label>
          </div>
          <div class="checkbox">
            <label for="notify-me-major-changes">
              <input id="notify-me-major-changes" type="checkbox" name="major_changes" value="on" /> Major changes to
              existing entries of this search
            </label>
          </div>
          <p>Notifications will be sent out about once per week if there are any changes.</p>
          <p>To stop any notification, you can click on the link at the bottom of the notification email or modify it from your <a href="/user/<?= $GLOBALS['user']->uid ?>/email-notifications">Email Notifications</a> dashboard.</p>
          <button type="button" class="btn btn-default" data-dismiss="modal">Cancel</button>
          <button type="submit" class="btn btn-primary pull-right">Send Notifications</button>
        </form>
      </div>
    </div>
  </div>
</div>
