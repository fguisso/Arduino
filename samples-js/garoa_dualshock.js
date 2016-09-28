var five = require('johnny-five')
  , board = new five.Board({repl:false})
  , dualShock = require('dualshock-controller')
  , controller = dualShock({
  	config: "dualshock3",
  	accelerometerSmoothing: true,
  	analogSickSmoothing: false
  });

board.on('ready', function(){
	var a = new five.Led(11)
	  , b = new five.Led(10)
	  , c = new five.Led(8)
	  , d = new five.Led(7)
	  , e = new five.Led(6)
	  , f = new five.Led(12)
	  , g = new five.Led(13);
	  // , dp = new fiveLed();

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
		console.log(data);
		d.off();
	});

	controller.on("square:press", function(data){
		console.log(data);
		e.on();
	});

	controller.on("square:release", function(data){
		console.log(data);
		e.off();
	});

	controller.on("l1:press", function(data){
		console.log(data);
		f.on();
	});

	controller.on("l1:release", function(data){
		console.log(data);
		f.off();
	});

	controller.on("triangle:press", function(data){
		console.log(data);
		g.on();
	});

	controller.on("triangle:release", function(data){
		console.log(data);
		g.off();
	});

	// controller.on("l2:press", function(data){
	// 	console.log(data+"press");
	// 	dp.on();
	// });

	// controller.on("l2:release", function(data){
	// 	console.log(data+"release");
	// 	dp.off();
	// });

	controller.connect();
});