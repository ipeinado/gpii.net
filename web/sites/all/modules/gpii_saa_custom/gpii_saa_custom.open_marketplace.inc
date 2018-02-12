<?php
/**
 * This .inc file contains most of the logic for the OpenMarketplace PayPal integration
 */

  function _gpii_saa_custom_create_order($order) {
    //dpm('It worked!');


    // load the product record to get pricing and other info needed for payment processing
    $product = node_load($order['product']);
    $order['amount'] = $product->field_product_price['und'][0]['value'];
    // fill in dummy values for tax and product name
    $order['payment'] = array(
      'amount' => $order['amount'],
      'description' =>  $product->title,
      'name' => preg_replace('@[^a-z0-9-]+@','_', strtolower($product->title)),
      'quantity' => $order['quantity'],
      'tax_rate' => 0,
    );

    //dpm($order);

    // pull in some user info in case the person placing the order is logged in
    global $user;

    // use entity_create to create our new package node
    $values = array(
      'type' => 'order',
      'uid' => $user->uid,
      'status' => 1,
      'comment' => 0,
      'promote' => 0,
    );

    $entity = entity_create('node', $values);

    // Now create an entity_metadata_wrapper around the node entity
    // to make getting and setting values easier
    $ewrapper = entity_metadata_wrapper('node', $entity);

    $ordernumber = variable_get('gpii_saa_ordernumber', '1');
    $ordernumber = $ordernumber + 1;
    variable_set('gpii_saa_ordernumber', $ordernumber);

    // Auto Label doesn't give us a good way to automatically number orders (variable approach above doesn't work the same way it does here), so we set a warning on node edit form and handle the numbering here.

    $ewrapper->title->set('Order #' . $ordernumber);

    // add the individual fields based on the $order array
    $ewrapper->field_first_name->set($order['first_name']);
    $ewrapper->field_last_name->set($order['last_name']);
    $ewrapper->field_email->set($order['email']);
    $ewrapper->field_order_notes->set($order['notes']);

    // add the payment info
    $entity->field_payment[LANGUAGE_NONE][0] = $order['payment'];

    // Note that the entity id must be passed as an integer not a string
    $ewrapper->field_product_reference->set(intval($order['product']));

    // Now just save the wrapper and the entity
    $ewrapper->save(true);
    entity_save('node', $entity);

    $_SESSION['gpii_saa_custom_package_orders'][] .= $entity->nid;

    // redirect to the newly created node
    drupal_goto('/node/' . $entity->nid);

    return;
  }


    function _gpii_saa_custom_update_order($order, $order_id) {
    //dpm('It worked!');


    // load the product record to get pricing and other info needed for payment processing
    $product = node_load($order['product']);
    $order['amount'] = $product->field_product_price['und'][0]['value'];
    // fill in dummy values for tax and product name
    $order['payment'] = array(
      'amount' => $order['amount'],
      'description' =>  $product->title,
      'name' => preg_replace('@[^a-z0-9-]+@','_', strtolower($product->title)),
      'quantity' => $order['quantity'],
      'tax_rate' => 0,
    );

    //dpm($order);

    // pull in some user info in case the person placing the order is logged in
    global $user;

    $entity = node_load($order_id);

    // Now create an entity_metadata_wrapper around the node entity
    // to make getting and setting values easier
    $ewrapper = entity_metadata_wrapper('node', $entity);

    // add the individual fields based on the $order array
    $ewrapper->field_first_name->set($order['first_name']);
    $ewrapper->field_last_name->set($order['last_name']);
    $ewrapper->field_email->set($order['email']);
    $ewrapper->field_order_notes->set($order['notes']);

    // add the payment info
    $entity->field_payment[LANGUAGE_NONE][0] = $order['payment'];

    // Note that the entity id must be passed as an integer not a string
    $ewrapper->field_product_reference->set(intval($order['product']));

    // Now just save the wrapper and the entity
    $ewrapper->save(true);
    $entity->revision = TRUE;
    entity_save('node', $entity);

    $_SESSION['gpii_saa_custom_package_orders'][] .= $entity->nid;

    // redirect to the updated node
    drupal_goto('/node/' . $entity->nid);

    return;
  }

?>
