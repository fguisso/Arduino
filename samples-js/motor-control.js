var five = require('johnny-five')
  , board = new five.Board({repl:false})
  , dualShock = require('dualshock-controller')
  , controller = dualShock({
  	config: "dualshock3",
  	accelerometerSmoothing: true,
  	analogSickSmoothing: false
  });

controller.on('error', function(data){
	console.log('Deu erro!');
});

board.on('ready', function(){
	var pin_0 = new five.Pin(4)
	  , pin_1 = new five.Pin(3);

	controller.on('press:dpadUp', function(data){
		pin_0.high();
		pin_1.low();
	});
	controller.on('release:dpadUp', function(data){
		pin_0.low();
		pin_1.low();
	});
	controller.on('press:dpadDown', function(data){
		pin_0.low();
		pin_1.high();
	});
	controller.on('release:dpadDown', function(data){
		pin_0.low();
		pin_1.low();
	});
});