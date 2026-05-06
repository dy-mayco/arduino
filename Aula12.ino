/*
	Aula 12 - 06/05
    
    Objetivo: estudar o comportamento do LED RGB
*/

#define led_R 11
#define led_G 10
#define led_B 9

#define pot_R A0
#define pot_G A1
#define pot_B A2

// C++ code
//
void setup()
{
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  pinMode(pot_R, INPUT);
  pinMode(pot_G, INPUT);
  pinMode(pot_B, INPUT);
}

void loop(){
 //Lê os valores do potenciômetro (0 a 1023)
  int leituraR = analogRead(pot_R);
  int leituraG = analogRead(pot_G);
  int leituraB = analogRead(pot_B);
 //Converte paranescala do LED (0 a 255)
  int brilhoR = map(leituraR, 0, 1023, 0, 255);
  int brilhoG = map(leituraG, 0, 1023, 0, 255);
  int brilhoB = map(leituraB, 0, 1023, 0, 255);
  
  analogWrite(led_R, brilhoR);
  analogWrite(led_G, brilhoG);
  analogWrite(led_B, brilhoB);
}