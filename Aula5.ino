/****************************************************************
AULA 6 - Acionamento de LEDs por botão - 11/03/2026

Autor: Paulo Cesar / Dyony Mayco
****************************************************************/

//Denominar os pinos de ligação
#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define botao 2

//variaveis de controle
int modo = 0;  // 0: desligado, l
bool botaoPressionado = false;
int tempo = 400;

// modo de ligação dos pinos
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(botao, INPUT_PULLUP);  //RESISTÊNCIA INTERNA

  //inicializa o gerador aleatório
  randomSeed(analogRead(0));
}

void loop() {

  bool leitura = digitalRead(botao);
  if (leitura == LOW && !botaoPressionado) {
    modo++;                  //soma l ao modo atual
    if (modo > 2) modo = 0;  //se passar de volta pra 0
    botaoPressionado = true;
    delay(30);
  }

  if (leitura == HIGH && botaoPressionado) {
    botaoPressionado = false;
  }
  //execuções das funções em modo
  if (modo == 1) {
    sequenciavaivem();
  } else if (modo == 2) {
    sequenciaAleatoria();
  } else {
    desligarTodos();
  }
}

void sequenciavaivem() {

  int pinos[] = { led1, led2, led3, led4, led5 };
  //ida
  for (int i = 0; i < 5; i++) {
    if (digitalRead(botao) == LOW && !botaoPressionado) return;
    digitalWrite(pinos[i], HIGH);
    delay(tempo);
    digitalWrite(pinos[i], LOW);
  }
  //volta
  for (int i = 4; i >= 0; i--) {
    if (digitalRead(botao) == LOW && !botaoPressionado) return;
    digitalWrite(pinos[i], HIGH);
    delay(tempo);
    digitalWrite(pinos[i], LOW);
  }
}
void desligarTodos() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}

//Função aleatória para ligar LEDs
void sequenciaAleatoria() {
  int pinos[] = { led1, led2, led3, led4, led5 };
  int sorteio = random(0, 5);  //sorteia um indice de 0 a 4
  digitalWrite(pinos[sorteio], HIGH);
  delay(tempo);
  digitalWrite(pinos[sorteio], LOW);
}