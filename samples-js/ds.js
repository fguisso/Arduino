var dualShock = require('dualshock-controller')
  , controller = dualShock({
  	config: "dualshock3",
  	accelerometerSmoothing: true,
  	analogSickSmoothing: true
  });

  controller.on('left:move', function(data){
  	console.log(data);
  });