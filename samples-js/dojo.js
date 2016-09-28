var five = require('johnny-five')
  , board = new five.Board({repl: false, port: '/dev/cu.CPTANK-DevB'});

board.on('ready', function(){
	var a = new five.Led(8)
	  , b = new five.Led(9)
	  , c = new five.Led(10)
	  , d = new five.Led(11)
	  , e = new five.Led(12)
	  , f = new five.Led(13)
	  , g = new five.Led(7)
	  , dp = new five.Led(6)
	  , count = 0;

	  // this.wait(ms, function(){});

	this.loop(1000, function(){
		switch(count){
			case 0 : dp.off();
						a.on();
						break
			case 1 : a.off();
						b.on();
						break
			case 2 : b.off();
						c.on();
						break
			case 3 : c.off();
						d.on();
						break
			case 4 : d.off();
						e.on();
						break
			case 5 : e.off();
						f.on();
						break
			case 6 : f.off();
						g.on();
						break
			case 7 : g.off();
						dp.on();
						break
		}
		count++;
		if(count == 8){
			count = 0;
		};
	});

	// this.loop(200, function(){
	// 	switch(count){
	// 		case 0 : f.off();
	// 					a.on();
	// 					break
	// 		case 1 : a.off();
	// 					b.on();
	// 					break
	// 		case 2 : b.off();
	// 					c.on();
	// 					break
	// 		case 3 : c.off();
	// 					d.on();
	// 					break
	// 		case 4 : d.off();
	// 					e.on();
	// 					break
	// 		case 5 : e.off();
	// 					f.on();
	// 					break
	// 	}
	// 	count++;
	// 	if(count == 6){
	// 		count = 0;
	// 	};

	// });
});