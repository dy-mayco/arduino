/************************************************************************************************************************
  COLÉGIO ESTADUAL GABRIEL DE LARA - 22/04/2026
  AUTOR_ Dyony Mayco Rodrigues 

  OBJETIVO_ Estudar o dunciamento do JooyStick Shield
************************************************************************************************************************/

//não alterar os números das portas
#define botaoA 2
#define botaoB 3
#define botaoC 4
#define botaoD 5
#define botaoE 6
#define botaoF 7
#define botaoK 8
//mapeamento dos eixos X e Y (0 a 1023)
#define eixoX A0
#define eixoY A1

void setup() {
  for (int btn = 2; btn <= 8; btn++ ) {
    pinMode(btn, INPUT_PULLUP);
  }
  Serial.begin(9600);
  Serial.println("Sistema iniciado. Precione um botao...");
}

void loop() {
  //leitura dos valoresbanalógicos de 0 a 1023
  int valorX = analogRead(eixoX);
  int valorY = analogRead(eixoY);
  int t = digitalRead(botaoA);
  int o = digitalRead(botaoB);
  int x = digitalRead(botaoC);
  int q = digitalRead(botaoD);
  int start = digitalRead(botaoE);
  int select = digitalRead(botaoF);
  int L3 = digitalRead(botaoK);

  //exibir no monitor serial
  Serial.print("X: ");
  Serial.print(valorX);
  Serial.print(" | Y: ");
  Serial.println(valorY);

  //Ação
  if (valorX > 600) {Serial.println("Movendo para a DIREITA");}
  if (valorX < 450) {Serial.println("Movendo para a ESQUERDA");}
  if (valorX > 600) {Serial.println("Movendo para CIMA");}
  if (valorX < 450) {Serial.println("Movendo para BAIXO");}
  delay(1000);

  //verificar cada botão. Como usamos INPUT_PULLUP então LOW significa pressionar
  if (t == LOW ) {Serial.println("T pressionada");
  delay(100);
  }
  if (o == LOW ) {Serial.println("O pressionada");
  delay(100);
  }
  if (x == LOW ) {Serial.println("X pressionada");
  delay(100);
  }
  if (q == LOW ) {Serial.println("Q pressionada");
  delay(100);
  }
  if (start == LOW ) {Serial.println("Start pressionada");
  delay(100);
  }
  if (select == LOW ) {Serial.println("Select pressionada");
  delay(100);
  }
  if (L3 == LOW ) {Serial.println("L3 pressionada");
  delay(100);
  }
}
