var five = require('johnny-five');
//var board = new five.Board({repl: true, port: '/dev/cu.CPTANK-DevB'});
var board = new five.Board();

board.on('ready', function(){
	console.log('Estou on na bagaça');
	var led = new five.Led(13);
	led.strobe();
//	var pino = new five.Pin(4);
//	var pina = new five.Pin(5);
	
	//pin10.low();
	//pin9.low();
	//pin9.high();	
	
//	this.repl.inject({
	
//	pino: pino,
//	pina: pina
//	});
});
