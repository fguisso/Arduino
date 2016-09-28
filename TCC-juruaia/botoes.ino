int a = 7;
int b = 8;
int c = 9;
int d = 4;
int e = 5;
int f = 6;
int g = 10;
//leobsegreti@live.com
#define digit1 A1
#define digit2 A0

#define Botao1 A2
#define Botao2 A3
#define BotaoReset A5
#define PositivoBotoes A4

#define SEG_ON LOW
#define SEG_OFF HIGH

// int rele = 13;
// int rele2 = 12;
// int rele3 = 11;

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
  
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
}

// void loop(){
//   digitalWrite(PositivoBotoes, HIGH);
//   if(digitalRead(Botao1) == HIGH){
//     pov(14);
//   }
//   if(digitalRead(Botao2) == HIGH){
//     pov(8);
//   }
//   if(digitalRead(BotaoReset) == LOW){
//     pov(5);
//   }
// }

void loop(){
  static unsigned long timer = millis();
  static int tempo = 0;

  numeros(10);
  digitalWrite(PositivoBotoes, HIGH);

  int red = 0, green = 0;


    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    
  
  if(digitalRead(Botao1) == HIGH){
    tempo = 21;
    green++;
    digitalWrite(PositivoBotoes, LOW); //Desabilita botões
      
    }

  while(green > 0){
    if (millis() >= timer) {
      timer += 1200; 
      tempo--;
    }
    pov(tempo);
    if(tempo == 0){
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    }else{
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
    if(digitalRead(BotaoReset) == LOW){
    red = 0;
    green = 0;
    numeros(10);
    digitalWrite(PositivoBotoes, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
}

  if(digitalRead(Botao2) == HIGH){
    tempo = 21;
    red++;
    digitalWrite(PositivoBotoes, LOW); //Desabilita botões
  }

  while(red > 0){
    if (millis() >= timer) {
      timer += 1200; 
      tempo--;
    }
    
    pov(tempo);
    if(tempo == 0){
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    }else{
      digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    }
    if(digitalRead(BotaoReset) == LOW){
    red = 0;
    green = 0;
    numeros(10);
    digitalWrite(PositivoBotoes, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
  }

  
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