<button
  id="notify-me-button"
  type="button"
  class="btn btn-primary"
  data-toggle="modal"
  data-target="#notify-me-modal"
  data-toggle="tooltip" data-placement="right" title="Get notified when this product's page in the Unified Listing changes."
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
          Get notified when this product's page in the Unified Listing changes
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
          You already are subscribed to email notifications for this product. To manage your email notifications visit
          the
          <a href="/user/<?= $GLOBALS['user']->uid ?>/email-notifications">Email Notifications</a> page on your profile.
        </p>
      </div>
      <div class="modal-body notify-me-success">
        <p>success!</p>
      </div>
      <div class="modal-body notify-me-form">
        <form id="notify-me-form-save">
          <input type="hidden" name="uid" value="<?= $GLOBALS['user']->uid ?>" />
          <input type="hidden" name="nid" value="<?= arg(1) ?>" />
          <input type="hidden" name="search_type" value="product" />

          <div class="alert alert-danger alert-dismissible notify-me-error" role="alert">
            Something went wrong. Please try again later.
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </button>
          </div>
          <p>
            You will be notified by email when there are major changes to this product's entry in the Unified Listing.
          </p>
          <p>Notifications will be sent about once per week if there are any changes.</p>
          <p>To stop any notification, you can click on the link at the bottom of the notification email.</p>
          <button type="button" class="btn btn-default" data-dismiss="modal">Cancel</button>
          <button type="submit" class="btn btn-primary pull-right">Send Notifications</button>
        </form>
      </div>
    </div>
  </div>
</div>
