(function($) {
  $().ready(function() {
    $('.profile-header-image img').mouseover(function() {
      $('#participant-profile-home .center-wrapper').css({'margin-top':'0','background-color': 'rgba(255,255,255,0)'});
    }).mouseout(function() {
      $('#participant-profile-home .center-wrapper').css({'margin-top':'','background-color': ''});
    });
  });
}(jQuery));