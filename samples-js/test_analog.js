var five = require('johnny-five')
  , board = new five.Board({repl:false, port: '/dev/cu.CPTANK-DevB'})
  , dualShock = require('dualshock-controller')
  , controller = dualShock({
  	config: "dualshock3",
  	accelerometerSmoothing: true,
  	analogSickSmoothing: true
  })
  , axys_x = 0
  , axys_y = 0;

board.on('ready', function(){
	var a = new five.Led(8)
	  , b = new five.Led(9)
	  , c = new five.Led(10)
	  , d = new five.Led(11)
	  , e = new five.Led(12)
	  , f = new five.Led(13)
	  , g = new five.Led(7)
	  , dp = new five.Led(6);

	controller.on("left:move", function(data){
		if(data.y >= 127){
			axys_y = 1;
		}else{
			axys_y = 0;
		}
		if(data.x <= 85){
			axys_x = 0;
		}
		if(data.x >= 86 && data.x <= 170){
			axys_x = 1;
		}
		if(data.x >= 171){
			axys_x = 2;
		}

		if(axys_x == 0 && axys_y == 0){
			f.on();
			a.off();
			b.off();
			c.off();
			d.off();
			e.off();
		}
		if(axys_x == 0 && axys_y == 1){
			f.off();
			a.off();
			b.off();
			c.off();
			d.off();
			e.on();
		}
		if(axys_x == 1 && axys_y == 0){
			f.off();
			a.on();
			b.off();
			c.off();
			d.off();
			e.off();
		}
		if(axys_x == 1 && axys_y == 1){
			f.off();
			a.off();
			b.off();
			c.off();
			d.on();
			e.off();
		}
		if(axys_x == 2 && axys_y == 0){
			f.off();
			a.off();
			b.on();
			c.off();
			d.off();
			e.off();
		}
		if(axys_x == 2 && axys_y == 1){
			f.off();
			a.off();
			b.off();
			c.on();
			d.off();
			e.off();
		}
		// console.log("X = "+ data.x+" : Y = "+data.y);
	});

	controller.connect();
});