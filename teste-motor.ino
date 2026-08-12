#include <AFMotor.h>

// Instanciação dos motores (M2 = Motor Esquerdo | M3 = Motor Direito)
AF_DCMotor motorEsq(3); 
AF_DCMotor motorDir(2);

// --- CONSTANTES DE CALIBRAÇÃO DEFINIDAS ---
const int VEL_BASE_ESQ = 100; // Velocidade calibrada do motor esquerdo
const int VEL_BASE_DIR = 60;  // Velocidade calibrada do motor direito

// Variáveis globais para controlo atual de velocidade
int velocidadeEsq = 0; 
int velocidadeDir = 0;

// --- PROTÓTIPOS DAS FUNÇÕES ---
void frente();
void re();
void parada();
void giroHorario();
void giroAntiHorario();
void giroEixoHorario();
void giroEixoAntiHorario();
void definirVelocidades(int velEsq, int velDir);

void setup() {
  Serial.begin(9600);
  
  // Aplica os valores calibrados para que o robô ande reto
  definirVelocidades(VEL_BASE_ESQ, VEL_BASE_DIR); 
  
  // Garante que o robô inicia parado
  parada();
  
  Serial.println("==========================================");
  Serial.println("  ROBÓ CALIBRADO PRONTO PARA O TESTE");
  Serial.println("==========================================");
  Serial.print("Velocidade Esquerda (M2): "); Serial.println(VEL_BASE_ESQ);
  Serial.print("Velocidade Direita  (M3): "); Serial.println(VEL_BASE_DIR);
  Serial.println("------------------------------------------");
}

void loop() {
  // Rotina sequencial de testes de movimentação
  Serial.println("1. Movendo para FRENTE (Linha Reta)");
  frente();
  delay(3000); // Anda por 3 segundos para validar a calibração
  
  Serial.println("2. Movendo para TRÁS (Ré)");
  re();
  delay(3000);
  
  Serial.println("3. Giro Horário (Pivotado - Eixo na roda direita)");
  giroHorario();
  delay(1500);
  
  Serial.println("4. Giro Anti-Horário (Pivotado - Eixo na roda esquerda)");
  giroAntiHorario();
  delay(1500);
  
  Serial.println("5. Giro SOBRE O EIXO CENTRAL (Sentido Horário)");
  giroEixoHorario();
  delay(1500);
  
  Serial.println("6. Giro SOBRE O EIXO CENTRAL (Sentido Anti-Horário)");
  giroEixoAntiHorario();
  delay(1500);
  
  Serial.println("7. Parada de Segurança");
  parada();
  
  // Aguarda 5 segundos antes de reiniciar toda a rotina de testes
  Serial.println("\nAguardando 5 segundos para reiniciar o ciclo...\n");
  delay(5000);
}

// =======================================================
// FUNÇÕES DE MOVIMENTAÇÃO (Ajustadas com a Calibração)
// =======================================================

// Atualiza a velocidade física de ambos os motores respeitando os limites do Arduino (0-255)
void definirVelocidades(int velEsq, int velDir) {
  velocidadeEsq = constrain(velEsq, 0, 255);
  velocidadeDir = constrain(velDir, 0, 255);
  
  motorEsq.setSpeed(velocidadeEsq);
  motorDir.setSpeed(velocidadeDir);
}

// Move o robô para FRENTE em linha reta usando os valores calibrados
void re() {
  definirVelocidades(VEL_BASE_ESQ, VEL_BASE_DIR);
  motorEsq.run(FORWARD);
  motorDir.run(FORWARD);
}

// Move o robô para TRÁS em linha reta usando os valores calibrados
void fente() {
  definirVelocidades(VEL_BASE_ESQ, VEL_BASE_DIR);
  motorEsq.run(BACKWARD);
  motorDir.run(BACKWARD);
}

// DESLIGA os dois motores completamente (Corta a energia)
void parada() {
  motorEsq.run(RELEASE);
  motorDir.run(RELEASE);
}

// GIRO HORÁRIO PIVOTADO (Roda esquerda avança com velocidade calibrada, direita para)
void giroHorario() {
  definirVelocidades(VEL_BASE_ESQ, 0); 
  motorEsq.run(FORWARD);
  motorDir.run(RELEASE);
}

// GIRO ANTI-HORÁRIO PIVOTADO (Roda direita avança com velocidade calibrada, esquerda para)
void giroAntiHorario() {
  definirVelocidades(0, VEL_BASE_DIR);
  motorEsq.run(RELEASE);
  motorDir.run(FORWARD);
}

// GIRO 360° SOBRE O PRÓPRIO EIXO (Sentido Horário)
void giroEixoHorario() {
  definirVelocidades(VEL_BASE_ESQ, VEL_BASE_DIR);
  motorEsq.run(FORWARD);
  motorDir.run(BACKWARD);
}

// GIRO 360° SOBRE O PRÓPRIO EIXO (Sentido Anti-Horário)
void giroEixoAntiHorario() {
  definirVelocidades(VEL_BASE_ESQ, VEL_BASE_DIR);
  motorEsq.run(BACKWARD);
  motorDir.run(FORWARD);
}
