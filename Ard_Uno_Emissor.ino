#include <SoftwareSerial.h>
#include <DHT.h>

// Pinos: RX (pino 2) para receber dados da Serial e TX (pino 7) para o Laser
SoftwareSerial mySerial(2, 7); // RX, TX (Laser)

// Definição do pino e tipo do sensor DHT11
#define DHTPIN 8     // O DHT11 está conectado ao pino 8
#define DHTTYPE DHT11 // Definindo o tipo do sensor como DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600); 
  while (!Serial) {
    ; // Espera para Arduinos com ATmega32u4 (USB Nativa)
  }

  // Inicializa o sensor DHT
  dht.begin();
  
  Serial.println("Envie o que quiser!"); // Mensagem inicial
  
  // Inicializa a comunicação com o módulo laser
  mySerial.begin(4800);
}

void loop() {
  // Lê a temperatura do sensor DHT11
  float temperature = dht.readTemperature();

  // Verifica se a leitura é válida
  if (isnan(temperature)) {
    Serial.println("Falha ao ler do sensor DHT11!");
    return;
  }

  // Envia a temperatura pela serial e via laser para o receptor
  Serial.print("Temperatura: ");
  Serial.println(temperature);
  
  // Envia o valor da temperatura para o Arduino Nano via laser
  mySerial.print(temperature);
  mySerial.println(); // Envia uma nova linha como delimitador

  // Verifica se há dados disponíveis na porta Serial
  while (Serial.available()) {
    char receivedChar = Serial.read(); // Lê o caractere da Serial
    mySerial.print(receivedChar); // Envia o caractere pelo laser
  }

  // Atraso para a próxima leitura
  delay(2000); // Faz leituras a cada 2 segundos
}
