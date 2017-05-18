/*jslint browser: true*/
/*global jQuery*/

(function ($) {
  'use strict';

  // Tag the body when viewed in IE to fix some style issues.
  $(document).ready(function(){
    if (navigator.userAgent.match(/MSIE/g)
        || navigator.userAgent.match(/Trident\/7.0/g)) {
      $(document.body).addClass('ie');
    }
  });

  // Set up ARIA roles where necessary. @@ needs review
  $(document).ready(function() {
    $('.region-branding').attr('role', 'banner');
    $('.region-content').attr('role', 'main');
    $('.footer').attr('role', 'contentinfo');
    $('.node').attr('role', 'article');
    $('.block').attr('role', 'complementary');
    $('#search-form').attr('role', 'search');
  });

  // Override default Bootstrap accordion behavior to force one item to always
  // be open. (makes open marketplace pages look less wonky when all collapsed)

  $(document).ready(function() {
    $('.panel-heading a').on('click',function(e){
      if($(this).parents('.panel').children('.panel-collapse').hasClass('in')){
        e.stopPropagation();
      }
      // You can also add preventDefault to remove the anchor behavior that makes
      // the page jump
       e.preventDefault();
    });
  });


  // Dynamically adjust the breakpoints based on font changes to the <html>
  // element from Fluid UI.
  $(document).ready(function(){
    var $html = $('html'),
        baseFontSize = 1,
        breakpoints = {};

    // The base font size and breakpoints (indices) must match the stylesheet.
    // The values represent the ratios at which the screen size should be forced
    // to the mobile version.
    baseFontSize = 14;
    breakpoints[768] = 1.2;
    breakpoints[992] = 1.4;
    breakpoints[1200] = 1.6;

    var callback = function() {
      var fontSize = parseFloat($html.css('font-size')),
          browserWidth = $html.width(),
          ratio = (fontSize / baseFontSize).toFixed(1),
          forceMobileLayout = false;

      for (var i in breakpoints) {
        if (browserWidth >= i) {
          forceMobileLayout = ratio >= breakpoints[i];
        } else {
          break;
        }
      }

      $html[forceMobileLayout ? 'addClass' : 'removeClass']('force-mobile-layout');
    };

    callback();
    $(window).resize(callback);
    $html.watch({properties: 'font-size', callback: callback});
  });

  // Add functionality for the tab that displays the translation options. It
  // mimics the FluidUI component and also makes the two work well together at
  // the top of the page.
  $(document).ready(function(){
    var $googleTranslate = $('#block-google-translator-active-languages'),
        $toggleContainer = $('#gpii-translate-toggle_container'),
        $toggleButton = $('#gpii-translate-toggle_button'),
        $fluidUiPanel = $('.fl-prefsEditor-separatedPanel'),
        duration = 400;

    $toggleButton.click(function(){
      var visible = $googleTranslate.is(':visible');

      setTimeout(function(){ $fluidUiPanel.toggle(); }, (visible ? duration : 0));
      $(this).text((visible ? '+  Translate To...' : '- Hide'));
      $googleTranslate.slideToggle({
        duration: duration,
        progress: function(){ $toggleContainer.css('top', $googleTranslate.outerHeight()+'px'); },
        complete: function(){
          $('.goog-te-combo').focus();
          if (visible) {
            $toggleContainer.css('top', '0px');
          }
        }
      });
    });

    $(window).resize(function(){
      var offset = $googleTranslate.is(':visible') ? $googleTranslate.outerHeight() : 0;
      $toggleContainer.css('top', offset+'px');
    });

    setTimeout(function(){
      $('.goog-te-combo').change(function(){ $toggleButton.click(); });
    }, 1500);

    $('#show-hide').click(function(){
      var visible = $(this).text().match(/^\s*\-/);

      setTimeout(function(){ $toggleContainer.toggle(); }, (visible ? duration : 0));

      // Temporarily modify the width of the FluidUI panel so that it doesn't
      // interfere with other elements at the top of the page, e.g., the
      // translation tab.
      if (!visible) {
        $fluidUiPanel.css('width', '100%');
      } else {
        setTimeout(function(){ $fluidUiPanel.css('width', 'auto'); }, 1000);
      }
      console.log(document.getElementById('iframe-focus'));
      if (document.getElementById('iframe-focus')) {
        $('#iframe-focus').focus();
      } else {
        $('.flc-prefsEditor-iframe').before('<a id="iframe-focus" href></a>');
        $('#iframe-focus').focus();
      }
    });
  });



}(jQuery));

// language switcher functionality
!function(t){function n(r){if(e[r])return e[r].exports;var o=e[r]={i:r,l:!1,exports:{}};return t[r].call(o.exports,o,o.exports,n),o.l=!0,o.exports}var e={};n.m=t,n.c=e,n.i=function(t){return t},n.d=function(t,e,r){n.o(t,e)||Object.defineProperty(t,e,{configurable:!1,enumerable:!0,get:r})},n.n=function(t){var e=t&&t.__esModule?function(){return t.default}:function(){return t};return n.d(e,"a",e),e},n.o=function(t,n){return Object.prototype.hasOwnProperty.call(t,n)},n.p="",n(n.s=2)}([function(t,n,e){(function(n,r){/*!
 * @overview es6-promise - a tiny implementation of Promises/A+.
 * @copyright Copyright (c) 2014 Yehuda Katz, Tom Dale, Stefan Penner and contributors (Conversion to ES6 API by Jake Archibald)
 * @license   Licensed under MIT license
 *            See https://raw.githubusercontent.com/stefanpenner/es6-promise/master/LICENSE
 * @version   4.1.0
 */
!function(n,e){t.exports=e()}(0,function(){"use strict";function t(t){return"function"==typeof t||"object"==typeof t&&null!==t}function o(t){return"function"==typeof t}function i(t){B=t}function u(t){G=t}function s(){return void 0!==z?function(){z(a)}:c()}function c(){var t=setTimeout;return function(){return t(a,1)}}function a(){for(var t=0;t<W;t+=2){(0,Z[t])(Z[t+1]),Z[t]=void 0,Z[t+1]=void 0}W=0}function f(t,n){var e=arguments,r=this,o=new this.constructor(h);void 0===o[tt]&&k(o);var i=r._state;return i?function(){var t=e[i-1];G(function(){return O(i,o,t,r._result)})}():j(r,o,t,n),o}function l(t){var n=this;if(t&&"object"==typeof t&&t.constructor===n)return t;var e=new n(h);return b(e,t),e}function h(){}function v(){return new TypeError("You cannot resolve a promise with itself")}function p(){return new TypeError("A promises callback cannot return that same promise.")}function d(t){try{return t.then}catch(t){return ot.error=t,ot}}function _(t,n,e,r){try{t.call(n,e,r)}catch(t){return t}}function y(t,n,e){G(function(t){var r=!1,o=_(e,n,function(e){r||(r=!0,n!==e?b(t,e):T(t,e))},function(n){r||(r=!0,A(t,n))},"Settle: "+(t._label||" unknown promise"));!r&&o&&(r=!0,A(t,o))},t)}function m(t,n){n._state===et?T(t,n._result):n._state===rt?A(t,n._result):j(n,void 0,function(n){return b(t,n)},function(n){return A(t,n)})}function w(t,n,e){n.constructor===t.constructor&&e===f&&n.constructor.resolve===l?m(t,n):e===ot?(A(t,ot.error),ot.error=null):void 0===e?T(t,n):o(e)?y(t,n,e):T(t,n)}function b(n,e){n===e?A(n,v()):t(e)?w(n,e,d(e)):T(n,e)}function g(t){t._onerror&&t._onerror(t._result),x(t)}function T(t,n){t._state===nt&&(t._result=n,t._state=et,0!==t._subscribers.length&&G(x,t))}function A(t,n){t._state===nt&&(t._state=rt,t._result=n,G(g,t))}function j(t,n,e,r){var o=t._subscribers,i=o.length;t._onerror=null,o[i]=n,o[i+et]=e,o[i+rt]=r,0===i&&t._state&&G(x,t)}function x(t){var n=t._subscribers,e=t._state;if(0!==n.length){for(var r=void 0,o=void 0,i=t._result,u=0;u<n.length;u+=3)r=n[u],o=n[u+e],r?O(e,r,o,i):o(i);t._subscribers.length=0}}function E(){this.error=null}function S(t,n){try{return t(n)}catch(t){return it.error=t,it}}function O(t,n,e,r){var i=o(e),u=void 0,s=void 0,c=void 0,a=void 0;if(i){if(u=S(e,r),u===it?(a=!0,s=u.error,u.error=null):c=!0,n===u)return void A(n,p())}else u=r,c=!0;n._state!==nt||(i&&c?b(n,u):a?A(n,s):t===et?T(n,u):t===rt&&A(n,u))}function P(t,n){try{n(function(n){b(t,n)},function(n){A(t,n)})}catch(n){A(t,n)}}function M(){return ut++}function k(t){t[tt]=ut++,t._state=void 0,t._result=void 0,t._subscribers=[]}function C(t,n){this._instanceConstructor=t,this.promise=new t(h),this.promise[tt]||k(this.promise),U(n)?(this._input=n,this.length=n.length,this._remaining=n.length,this._result=new Array(this.length),0===this.length?T(this.promise,this._result):(this.length=this.length||0,this._enumerate(),0===this._remaining&&T(this.promise,this._result))):A(this.promise,L())}function L(){return new Error("Array Methods must be provided an Array")}function I(t){return new C(this,t).promise}function q(t){var n=this;return new n(U(t)?function(e,r){for(var o=t.length,i=0;i<o;i++)n.resolve(t[i]).then(e,r)}:function(t,n){return n(new TypeError("You must pass an array to race."))})}function F(t){var n=this,e=new n(h);return A(e,t),e}function Y(){throw new TypeError("You must pass a resolver function as the first argument to the promise constructor")}function D(){throw new TypeError("Failed to construct 'Promise': Please use the 'new' operator, this object constructor cannot be called as a function.")}function K(t){this[tt]=M(),this._result=this._state=void 0,this._subscribers=[],h!==t&&("function"!=typeof t&&Y(),this instanceof K?P(this,t):D())}function N(){var t=void 0;if(void 0!==r)t=r;else if("undefined"!=typeof self)t=self;else try{t=Function("return this")()}catch(t){throw new Error("polyfill failed because global object is unavailable in this environment")}var n=t.Promise;if(n){var e=null;try{e=Object.prototype.toString.call(n.resolve())}catch(t){}if("[object Promise]"===e&&!n.cast)return}t.Promise=K}var Q=void 0;Q=Array.isArray?Array.isArray:function(t){return"[object Array]"===Object.prototype.toString.call(t)};var U=Q,W=0,z=void 0,B=void 0,G=function(t,n){Z[W]=t,Z[W+1]=n,2===(W+=2)&&(B?B(a):$())},H="undefined"!=typeof window?window:void 0,J=H||{},R=J.MutationObserver||J.WebKitMutationObserver,V="undefined"==typeof self&&void 0!==n&&"[object process]"==={}.toString.call(n),X="undefined"!=typeof Uint8ClampedArray&&"undefined"!=typeof importScripts&&"undefined"!=typeof MessageChannel,Z=new Array(1e3),$=void 0;$=V?function(){return function(){return n.nextTick(a)}}():R?function(){var t=0,n=new R(a),e=document.createTextNode("");return n.observe(e,{characterData:!0}),function(){e.data=t=++t%2}}():X?function(){var t=new MessageChannel;return t.port1.onmessage=a,function(){return t.port2.postMessage(0)}}():void 0===H?function(){try{var t=e(4);return z=t.runOnLoop||t.runOnContext,s()}catch(t){return c()}}():c();var tt=Math.random().toString(36).substring(16),nt=void 0,et=1,rt=2,ot=new E,it=new E,ut=0;return C.prototype._enumerate=function(){for(var t=this.length,n=this._input,e=0;this._state===nt&&e<t;e++)this._eachEntry(n[e],e)},C.prototype._eachEntry=function(t,n){var e=this._instanceConstructor,r=e.resolve;if(r===l){var o=d(t);if(o===f&&t._state!==nt)this._settledAt(t._state,n,t._result);else if("function"!=typeof o)this._remaining--,this._result[n]=t;else if(e===K){var i=new e(h);w(i,t,o),this._willSettleAt(i,n)}else this._willSettleAt(new e(function(n){return n(t)}),n)}else this._willSettleAt(r(t),n)},C.prototype._settledAt=function(t,n,e){var r=this.promise;r._state===nt&&(this._remaining--,t===rt?A(r,e):this._result[n]=e),0===this._remaining&&T(r,this._result)},C.prototype._willSettleAt=function(t,n){var e=this;j(t,void 0,function(t){return e._settledAt(et,n,t)},function(t){return e._settledAt(rt,n,t)})},K.all=I,K.race=q,K.resolve=l,K.reject=F,K._setScheduler=i,K._setAsap=u,K._asap=G,K.prototype={constructor:K,then:f,catch:function(t){return this.then(null,t)}},K.polyfill=N,K.Promise=K,K})}).call(n,e(1),e(3))},function(t,n){function e(){throw new Error("setTimeout has not been defined")}function r(){throw new Error("clearTimeout has not been defined")}function o(t){if(f===setTimeout)return setTimeout(t,0);if((f===e||!f)&&setTimeout)return f=setTimeout,setTimeout(t,0);try{return f(t,0)}catch(n){try{return f.call(null,t,0)}catch(n){return f.call(this,t,0)}}}function i(t){if(l===clearTimeout)return clearTimeout(t);if((l===r||!l)&&clearTimeout)return l=clearTimeout,clearTimeout(t);try{return l(t)}catch(n){try{return l.call(null,t)}catch(n){return l.call(this,t)}}}function u(){d&&v&&(d=!1,v.length?p=v.concat(p):_=-1,p.length&&s())}function s(){if(!d){var t=o(u);d=!0;for(var n=p.length;n;){for(v=p,p=[];++_<n;)v&&v[_].run();_=-1,n=p.length}v=null,d=!1,i(t)}}function c(t,n){this.fun=t,this.array=n}function a(){}var f,l,h=t.exports={};!function(){try{f="function"==typeof setTimeout?setTimeout:e}catch(t){f=e}try{l="function"==typeof clearTimeout?clearTimeout:r}catch(t){l=r}}();var v,p=[],d=!1,_=-1;h.nextTick=function(t){var n=new Array(arguments.length-1);if(arguments.length>1)for(var e=1;e<arguments.length;e++)n[e-1]=arguments[e];p.push(new c(t,n)),1!==p.length||d||o(s)},c.prototype.run=function(){this.fun.apply(null,this.array)},h.title="browser",h.browser=!0,h.env={},h.argv=[],h.version="",h.versions={},h.on=a,h.addListener=a,h.once=a,h.off=a,h.removeListener=a,h.removeAllListeners=a,h.emit=a,h.binding=function(t){throw new Error("process.binding is not supported")},h.cwd=function(){return"/"},h.chdir=function(t){throw new Error("process.chdir is not supported")},h.umask=function(){return 0}},function(t,n,e){"use strict";Object.defineProperty(n,"__esModule",{value:!0});var r=e(0);!function(t){function n(t){return e(t).then(function(t){var n=t.innerText;return new r.Promise(function(e,r){var o=setInterval(function(){t.innerText!==n&&(clearInterval(o),e(t))},250)})})}function e(t){return new r.Promise(function(n,e){var r=setInterval(function(){var e=document.querySelector(t);e&&(clearInterval(r),n(e))},250)})}function o(t){var e=["de","el","es","en"],r=window.location.href.split("/"),o=t.target.value,i=r[3];e.indexOf(i)>-1?"en"!==o?r.splice(3,1,o):(r.splice(3,1),window.location.href=r.join("/")):r.splice(3,0,o),n("#block-bean-footer-about").then(function(){window.location.href=r.join("/")})}e(".goog-te-combo").then(function(n){return null===document.querySelector('option[value="en"]')&&t(n).children().eq(1).after(new Option("English","en")),n}).then(function(t){return t.addEventListener("change",o)})}(window.jQuery)},function(t,n){var e;e=function(){return this}();try{e=e||Function("return this")()||(0,eval)("this")}catch(t){"object"==typeof window&&(e=window)}t.exports=e},function(t,n){}]);
