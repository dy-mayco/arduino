/****************************************************************
AULA 2 - Sequência de LEDs - 25/02/2026

Autor: Gustavo Sauter / Dyony Mayco
****************************************************************/

//nomear variáveis
int tempo = 100;

//Denominar os pinos de ligação
#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9

// modo de ligação dos pinos
void setup() {
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(led5, OUTPUT);
}

void loop() {
 digitalWrite(led1, HIGH);
 delay(tempo);

 digitalWrite(led2, HIGH);
 delay(tempo);
 
 digitalWrite(led3, HIGH);
 delay(tempo);
 
 digitalWrite(led4, HIGH);
 delay(tempo);
 
 digitalWrite(led5, HIGH);
 delay(100);

 digitalWrite(led5, LOW);
 delay(tempo);

 digitalWrite(led4, LOW);
 delay(tempo);
 
 digitalWrite(led3, LOW);
 delay(tempo);
 
 digitalWrite(led2, LOW);
 delay(tempo);
 
 digitalWrite(led1, LOW);
 delay(tempo);
}
