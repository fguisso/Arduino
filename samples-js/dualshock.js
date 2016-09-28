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

	controller.on('error', function(data){
		console.log("Deu erro!");
	});

	controller.on('battery:change', function(value){
		console.log("Bateria: " + value);
	});

	controller.on("r2:press", function(data){
		console.log(data);
		a.on();
	});

	controller.on("r2:release", function(data){
		console.log(data);
		a.off();
	});

	controller.on("r1:press", function(data){
		console.log(data);
		b.on();
	});

	controller.on("r1:release", function(data){
		console.log(data);
		b.off();
	});

	controller.on("circle:press", function(data){
		console.log(data);
		c.on();
	});

	controller.on("circle:release", function(data){
		console.log(data);
		c.off();
	});

	controller.on("x:press", function(data){
		console.log(data);
		d.on();
	});

	controller.on("x:release", function(data){
		console.log(data+"release");
		d.off();
	});

	controller.on("square:press", function(data){
		console.log(data+"spres");
		e.on();
	});

	controller.on("square:release", function(data){
		console.log(data+"release");
		e.off();
	});

	controller.on("l1:press", function(data){
		console.log(data+"press");
		f.on();
	});

	controller.on("l1:release", function(data){
		console.log(data+"release");
		f.off();
	});

	controller.on("triangle:press", function(data){
		console.log(data+"s"+":press");
		g.on();
	});

	controller.on("triangle:release", function(data){
		console.log(data+"s"+":release");
		g.off();
	});

	controller.on("l2:press", function(data){
		console.log(data+"press");
		dp.on();
	});

	controller.on("l2:release", function(data){
		console.log(data+"release");
		dp.off();
	});

	controller.connect();
});