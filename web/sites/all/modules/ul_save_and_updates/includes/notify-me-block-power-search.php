<div id="notify-me-modal" tabindex="-1" role="dialog">
  <div role="document">
    <div class="modal-header">
      <button type="button" class="close" data-dismiss="modal" aria-label="Close">
        <span aria-hidden="true">&times;</span>
      </button>
      <h3 class="modal-title">
        Power Search Actions
      </h3>
    </div>
    <div class="modal-body notify-me-share">
      <h4>Share this search</h4>
      <p>
        Click on the icon below to copy the sharable link to your clipboard. Visiting this link will run a search with
        the currently selected keywords and filters applied.
      </p>
      <div class="form-inline">
        <div class="form-group">
          <input
            id="sharelink"
            class="form-control"
            aria-invalid="false"
            ng-value="::lc.shareableLink"
          />
        </div>
        <button class="share-link-copy btn btn-default">
          <span class="sr-only">Copy link to clipboard</span>
          <span class="fa fa-clipboard"></span>
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
      <p>success!</p>
    </div>
    <div class="modal-body notify-me-form">
      <h4>Save this search</h4>
      <form id="notify-me-form-save">
        <input type="hidden" name="uid" value="<?= $GLOBALS['user']->uid ?>" />
        <input type="hidden" name="search_type" value="power_search" />
        <input type="hidden" name="search_url" ng-value="::lc.shareableLink"  />

        <div class="alert alert-danger alert-dismissible notify-me-error" role="alert">
          Something went wrong. Please try again later.
          <button type="button" class="close" data-dismiss="alert" aria-label="Close">
            <span aria-hidden="true">&times;</span>
          </button>
        </div>
        <div class="form-group">
          <label for="searchName">Give this search a name (optional)</label>
          <input type="text" class="form-control" id="searchName" name="search_name" value="10/25/19 - button" />
        </div>

        <p>Notify me with the following types of search result changes:</p>
        <div class="checkbox">
          <label>
            <input type="checkbox" name="new_entries" value="off" />
            <input id="notify-me-new-entries" type="checkbox" name="new_entries" /> New entries to this search
          </label>
        </div>
        <div class="checkbox">
          <label>
            <input type="checkbox" name="major_changes" value="off" />
            <input id="notify-me-major-changes" type="checkbox" name="major_changes" value="on" /> Major changes to
            existing entries of this search
          </label>
        </div>
        <p>Notifications will be sent out about once per week if there are any changes.</p>
        <p>To stop any notification you can click on the link at the bottom of the notification email.</p>
        <button type="button" class="btn btn-default" data-dismiss="modal">Cancel</button>
        <button type="submit" class="btn btn-primary">Send Notifications</button>
      </form>
    </div>
  </div>
</div>
