/****************************************************************
AULA 3 - Acionamento de LEDs por botão - 04/03/2026

Autor: Gustavo Sauter / Dyony Mayco
****************************************************************/

//Denominar os pinos de ligação
#define led1 13
#define led2 12
#define led3 11
#define botao 2

bool estadoLED = false;
bool botaoPressionado = false;

int tempo = 1000;

// modo de ligação dos pinos
void setup() {
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(botao, INPUT_PULLUP);//RESISTÊNCIA INTERNA
}

void loop() {
 //lógica de leitura: o PULLUP pressionado retorna LOW
  bool leitura = digitalRead(botao);
  
  //verifica se o botão foi apertado (transição de HIGH para LOW)
  if (leitura == LOW && !botaoPressionado) {
    estadoLED = !estadoLED; //inverte o estado
    delay(tempo);
    digitalWrite(led1, estadoLED);
    delay(tempo);
    digitalWrite(led2, estadoLED);
    delay(tempo);
    digitalWrite(led3, estadoLED);
    delay(tempo);

    botaoPressionado = true; //marca que o botão ainda está pressionado
    delay(50);//respiro para evitar ruído (bouce)
  }
  
  //verificar se o botão foi solto para permitir novo click
  if (leitura == HIGH && botaoPressionado)
    botaoPressionado = false;
}