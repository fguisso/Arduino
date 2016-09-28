var five = require('johnny-five')
  , board = new five.Board({repl:false, port: '/dev/cu.CPTANK-DevB'})
  , dualShock = require('dualshock-controller')
  , controller = dualShock({
  	config: "dualshock3",
  	accelerometerSmoothing: true,
  	analogSickSmoothing: true
  });

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
		if(data.x <= 42 && data.y >= 127){
			f.on();
			a.off();
			b.off();
			c.off();
			d.off();
			e.off();
		}
		if(data.x <= 127 && data.y >=42 && data.x >= 42 && data.y <= 213){
			e.on();
			a.off();
			b.off();
			c.off();
			d.off();
			f.off();
		}
		if(data.x >= 213 && data.y <=255){
			b.on();
			a.off();
			e.off();
			c.off();
			d.off();
			f.off();
		}
		if(data.x <= 255 && data.y >=127 && data.x >=213){
			c.on();
			a.off();
			b.off();
			e.off();
			d.off();
			f.off();
		}
		if(data.x >= 42 && data.x <= 213 && data.y <=42){
			a.on();
			e.off();
			b.off();
			c.off();
			d.off();
			f.off();
		}
		if(data.x >= 42 && data.x <= 213 && data.y >= 213 && data.y <=255){
			d.on();
			e.off();
			b.off();
			c.off();
			a.off();
			f.off();
		}
		console.log(data.x+" : "+data.y);
	});

	controller.connect();
});