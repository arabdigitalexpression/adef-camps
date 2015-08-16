(function ($) {
  $().ready(function () {
    if ($('.profile-header-image img').length) {
      $('.profile-header-image img').mouseover(function () {
        $('#participant-profile-home .center-wrapper').css({'margin-top': '0', 'background-color': 'rgba(255,255,255,0)'});
      }).mouseout(function () {
        $('#participant-profile-home .center-wrapper').css({'margin-top': '', 'background-color': ''});
      });
    } else {
      $('#participant-profile-home .center-wrapper').css({'margin-top': '0', 'background-color': 'rgba(255,255,255,0)'});
    }
  });
}(jQuery));