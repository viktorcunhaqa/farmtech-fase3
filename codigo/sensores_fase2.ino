#include <DHT.h>

// ======================================================
// Projeto FarmTech Solutions - Fase 2
// Monitoramento de sensores agrícolas com ESP32
// Sensores utilizados:
// - DHT22 para umidade
// - LDR simulando leitura de pH
// - Botões simulando nutrientes N, P e K
// - Relé para controle de irrigação
// ======================================================

// ----- DEFINIÇÕES DO SENSOR DHT -----
#define DHTPIN 23
#define DHTTYPE DHT22

// ----- PINOS DOS BOTÕES NPK -----
#define N_PIN 32
#define P_PIN 33
#define K_PIN 25

// ----- PINOS DO LDR E RELÉ -----
#define LDR_PIN 34
#define RELAY_PIN 26

// ----- OBJETO DO SENSOR DHT -----
DHT dht(DHTPIN, DHTTYPE);

// ----- VARIÁVEIS DE CONTROLE -----
float umidade = 0.0;
int valorLdr = 0;

int nitrogenio = 0;
int fosforo = 0;
int potassio = 0;

int nutrientesAtivos = 0;
bool ligarIrrigacao = false;

// ======================================================
// SETUP
// ======================================================
void setup() {
  Serial.begin(115200);

  // Inicializa o sensor DHT
  dht.begin();

  // Botões configurados com pull-up interno
  // Solto = HIGH
  // Pressionado = LOW
  pinMode(N_PIN, INPUT_PULLUP);
  pinMode(P_PIN, INPUT_PULLUP);
  pinMode(K_PIN, INPUT_PULLUP);

  // Configuração do relé
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  Serial.println("Sistema FarmTech iniciado.");
  Serial.println("Monitoramento de umidade, pH simulado e nutrientes NPK.");
}

// ======================================================
// LOOP PRINCIPAL
// ======================================================
void loop() {
  lerSensores();
  processarIrrigacao();
  exibirDadosSerial();
  controlarRele();

  delay(1000);
}

// ======================================================
// FUNÇÃO: Leitura dos sensores
// ======================================================
void lerSensores() {
  // Leitura da umidade pelo DHT22
  umidade = dht.readHumidity();

  // Leitura do LDR, utilizado como simulação de pH
  valorLdr = analogRead(LDR_PIN);

  // Leitura dos botões NPK
  // Como usamos INPUT_PULLUP:
  // pressionado = LOW
  // solto = HIGH
  nitrogenio = (digitalRead(N_PIN) == LOW) ? 1 : 0;
  fosforo = (digitalRead(P_PIN) == LOW) ? 1 : 0;
  potassio = (digitalRead(K_PIN) == LOW) ? 1 : 0;

  nutrientesAtivos = nitrogenio + fosforo + potassio;
}

// ======================================================
// FUNÇÃO: Lógica de irrigação
// ======================================================
void processarIrrigacao() {
  ligarIrrigacao = false;

  // Verifica se a leitura da umidade é válida
  if (!isnan(umidade)) {

    // Critérios para ligar irrigação:
    // 1. Umidade menor ou igual a 40%
    // 2. Pelo menos 2 nutrientes ativos
    // 3. LDR dentro da faixa considerada adequada
    if (umidade <= 40.0 && nutrientesAtivos >= 2 && valorLdr > 1000 && valorLdr < 3000) {
      ligarIrrigacao = true;
    }
  }
}

// ======================================================
// FUNÇÃO: Controle do relé
// ======================================================
void controlarRele() {
  if (ligarIrrigacao) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }
}

// ======================================================
// FUNÇÃO: Exibição dos dados no Monitor Serial
// ======================================================
void exibirDadosSerial() {
  Serial.println("--------------------------------");

  if (isnan(umidade)) {
    Serial.println("Erro ao ler umidade do sensor DHT22.");
  } else {
    Serial.print("Umidade do solo/ar: ");
    Serial.print(umidade);
    Serial.println("%");
  }

  Serial.print("Valor LDR simulando pH: ");
  Serial.println(valorLdr);

  Serial.print("Nitrogenio (N): ");
  Serial.println(nitrogenio);

  Serial.print("Fosforo (P): ");
  Serial.println(fosforo);

  Serial.print("Potassio (K): ");
  Serial.println(potassio);

  Serial.print("Total de nutrientes ativos: ");
  Serial.println(nutrientesAtivos);

  Serial.print("Status da irrigacao: ");

  if (ligarIrrigacao) {
    Serial.println("LIGADA");
  } else {
    Serial.println("DESLIGADA");
  }
}