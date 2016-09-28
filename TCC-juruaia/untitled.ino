int a = 7;
int b = 8;
int c = 9;
int d = 4;
int e = 5;
int f = 6;
int g = 10;

#define digit1 A2
#define digit2 A1

#define Botao1 A2
#define Botao2 A3
#define BotaoReset A4
#define PositivoBotoes A5

#define SEG_ON LOW
#define SEG_OFF HIGH

// long previousTimer = 0;
// long msegundos = 1000;
int tempo = 19;

void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
    
    pinMode(Botao1, INPUT);
    pinMode(Botao2, INPUT);
    pinMode(BotaoReset, INPUT);
    pinMode(PositivoBotoes, OUTPUT);
  
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop(){
  static unsigned long timer = millis();
    static int deciSeconds = 20;
  
    if (millis() >= timer) {
      deciSeconds--; // 100 milliSeconds is equal to 1 deciSecond
      timer += 1000; 
      if (deciSeconds == 0) { // Reset to 0 after counting for 1000 seconds.
        deciSeconds=20;
      }
    }

  pov(deciSeconds);
  digitalWrite(PositivoBotoes, HIGH);
  int red = 0, green = 0;
  if(digitalRead(Botao2) == HIGH){
    green++;
    digitalWrite(PositivoBotoes, LOW);
    digitalWrite(3, HIGH);
    delay(600);
    digitalWrite(3, LOW);
  }

  if(digitalRead(Botao1) == HIGH){
    red++;
    digitalWrite(PositivoBotoes, LOW);
    digitalWrite(3, HIGH);
    delay(600);
    digitalWrite(3, LOW);
  }

  while(red > 0){
    digitalWrite(5, HIGH);
    pov(tempo);
    if(digitalRead(BotaoReset) == HIGH){
      red = 0;
      green = 0;
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(PositivoBotoes, HIGH);
      numeros(10);
    }
  }
  while(green > 0){
    digitalWrite(4, HIGH);
    pov(tempo);
    if(digitalRead(BotaoReset) == HIGH){
      red = 0;
      green = 0;
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(PositivoBotoes, HIGH);
      numeros(10);
    }
  }
  //pov(millis()/1000);

  
}

void pov(int numeroPov){
  int unidade = numeroPov%10;
  int dezena = (numeroPov/10)%10;
  numeros(unidade);
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, LOW);
  delay(5);
  if(dezena == 1){
  numeros(dezena);
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, HIGH);
  }
  delay(5);
}

void numeros(int numero){

  switch (numero){
      case 0:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_ON);
        digitalWrite(e, SEG_ON);
        digitalWrite(f, SEG_ON);
        digitalWrite(g, SEG_OFF);
        break;
      case 1:
        digitalWrite(a, SEG_OFF);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_OFF);
        digitalWrite(e, SEG_OFF);
        digitalWrite(f, SEG_OFF);
        digitalWrite(g, SEG_OFF);
        break;
      case 2:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_OFF);
        digitalWrite(d, SEG_ON);
        digitalWrite(e, SEG_ON);
        digitalWrite(f, SEG_OFF);
        digitalWrite(g, SEG_ON);
        break;
      case 3:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_ON);
        digitalWrite(e, SEG_OFF);
        digitalWrite(f, SEG_OFF);
        digitalWrite(g, SEG_ON);
        break;
      case 4:
        digitalWrite(a, SEG_OFF);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_OFF);
        digitalWrite(e, SEG_OFF);
        digitalWrite(f, SEG_ON);
        digitalWrite(g, SEG_ON);
        break;
      case 5:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_OFF);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_ON);
        digitalWrite(e, SEG_OFF);
        digitalWrite(f, SEG_ON);
        digitalWrite(g, SEG_ON);
        break;
      case 6:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_OFF);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_ON);
        digitalWrite(e, SEG_ON);
        digitalWrite(f, SEG_ON);
        digitalWrite(g, SEG_ON);
        break;
      case 7:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_OFF);
        digitalWrite(e, SEG_OFF);
        digitalWrite(f, SEG_OFF);
        digitalWrite(g, SEG_OFF);
        break;
      case 8:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_ON);
        digitalWrite(e, SEG_ON);
        digitalWrite(f, SEG_ON);
        digitalWrite(g, SEG_ON);
        break;
      case 9:
        digitalWrite(a, SEG_ON);
        digitalWrite(b, SEG_ON);
        digitalWrite(c, SEG_ON);
        digitalWrite(d, SEG_ON);
        digitalWrite(e, SEG_OFF);
        digitalWrite(f, SEG_ON);
        digitalWrite(g, SEG_ON);
        break;
      //Apaga tudo
      case 10:
        digitalWrite(a, SEG_OFF);
        digitalWrite(b, SEG_OFF);
        digitalWrite(c, SEG_OFF);
        digitalWrite(d, SEG_OFF);
        digitalWrite(e, SEG_OFF);
        digitalWrite(f, SEG_OFF);
        digitalWrite(g, SEG_OFF);
        break;
  }
}