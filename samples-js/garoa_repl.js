var five = require('johnny-five');
var board = new five.Board();

board.on('ready', function(){

	var led = new five.Led(11);
	//Pino 11 é PWN - Modulacao por largura de pulso - 

	this.repl.inject({
		led: led

		// led.on();
		
		// led.off();
		
		// led.toggle();
		
		// led.strobe();
		
		// led.blink();
		
		// led.brightness(0 - 255);
		
		// led.fade(easing: "linear",
  //  				duration: 1000,
  //  				cuePoints: [0, 0.2, 0.4, 0.6, 0.8, 1],
  //  				keyFrames: [0, 250, 25, 150, 100, 125],
  //  				onstop: function() {
  //    			console.log("Animation stopped");
  //    			}
  //  		});

   		// led.pulse({
		// 		easing: "linear",
		// 		duration: 3000,
		// 		cuePoints: [0, 0.2, 0.4, 0.6, 0.8, 1],
		// 		keyFrames: [0, 10, 0, 50, 0, 255],
		// 		onstop: function() {
		// 		console.log("Animation stopped");
		// 		}
		// });

		// led.stop();

	});
});
