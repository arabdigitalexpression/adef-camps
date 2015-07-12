(function($) {
  Drupal.behaviors.tipsy = {
    attach: function(context, settings) {
      // Forms tooltips.
      if (Drupal.settings.tipsy.drupal_forms) {
        var formElement = $('.form-item');
        formElement.each(function(){
          var desc = $(this).find('.description');
          desc.css('display', 'none');
          if(desc.length > 0) {
            formSettings = Drupal.settings.tipsy.drupal_forms.options;
            $(this).find('input[type=text],input[type=password],textarea,select,.option').tipsy({
              title: function() { return desc.html(); },
              html: true,
              delayIn: parseInt(formSettings.delayIn),
                delayOut: parseInt(formSettings.delayOut),
                fade: parseInt(formSettings.fade),
                gravity: tipsy_determine_gravity(formSettings.gravity),
                offset: parseInt(formSettings.offset),
                opacity: parseFloat(formSettings.opacity),
                trigger: formSettings.trigger
            });
          }
        });
      }
      // Custom selectors tooltips.
      $.each(Drupal.settings.tipsy.custom_selectors, function(){
        var selector = $(this)[0].selector;
        var options = $(this)[0].options;
        var tooltipElement = $(selector);

        tooltipElement.tipsy({
          html: parseInt(options.html),
          delayIn: parseInt(options.delayIn),
          delayOut: parseInt(options.delayOut),
          fade: parseInt(options.fade),
          gravity: tipsy_determine_gravity(options.gravity),
          offset: parseInt(options.offset),
          opacity: parseFloat(options.opacity),
          trigger: options.trigger
        });
      });
    }
  };

  function tipsy_determine_gravity(g) {
    if (g == 'autoWE') { return $.fn.tipsy.autoWE; }
    else if (g == 'autoNS') { return $.fn.tipsy.autoNS; }
    else { return g; }
  }
})(jQuery);