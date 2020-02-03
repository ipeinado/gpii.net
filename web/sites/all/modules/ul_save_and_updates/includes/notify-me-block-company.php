<button
  id="notify-me-button"
  type="button"
  class="btn btn-primary notify-me-button"
  data-toggle="modal"
  data-target="#notify-me-modal"
  data-toggle="tooltip" data-placement="right" title="Get notified when product entries from this company are added or changed."
>
  <span class="fa fa-envelope"></span> Notify me of updates
</button>

<div id="notify-me-modal" class="modal fade" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
        <h3 class="modal-title">
          Get notified when product entries by this company change
        </h3>
      </div>
      <div class="modal-body notify-me-anon">
        <p>
          If you want to get email about product updates, you will need to sign up for an account with the Unified
          Listing.
        </p>
        <p>
          With an account, you can get email updates on specific products, categories of products, companies' products,
          and even custom searches for products.
        </p>
        <p><a href="/user/login">Log in now</a> or <a href="/user/register">create an account</a>.</p>
      </div>
      <div class="modal-body notify-me-exists">
        <p>
          You already are subscribed to email notifications for this company. To manage your subscriptions, visit
          the
          <a href="/user/<?= $GLOBALS['user']->uid ?>/email-notifications">Email Notifications</a> page on your profile.
        </p>
      </div>
      <div class="modal-body notify-me-success">
      <p>
          You have successfully subscribed to email notifications for this company. To manage your subscriptions, visit the
          <a href="/user/<?= $GLOBALS['user']->uid ?>/email-notifications">Email Notifications</a> tab on your user profile page.
        </p>
      </div>
      <div class="modal-body notify-me-form">
        <form id="notify-me-form-save">
          <input type="hidden" name="uid" value="<?= $GLOBALS['user']->uid ?>" />
          <input type="hidden" name="nid" value="<?= arg(1) ?>" />
          <input type="hidden" name="search_type" value="company" />

          <div id="notify-me-submit-failed" class="alert alert-danger alert-dismissible notify-me-error" role="alert">
            Something went wrong. Please try again later.
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </button>
          </div>
          <p>Notify me with the following types of product entry changes (select one or more):</p>
          <div class="checkbox">
            <label for="notify-me-new-entries">
              <input id="notify-me-new-entries" type="checkbox" name="new_entries" checked/> New entries from this company
            </label>
          </div>
          <div class="checkbox">
            <label for="notify-me-major-changes">
              <input id="notify-me-major-changes" type="checkbox" name="major_changes" value="on" /> Major changes to
              existing entries from this company
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
