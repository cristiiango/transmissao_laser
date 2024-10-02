// Importação de bibliotecas
#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// Pinos: RX (pino 7) para receber dados do receptor e TX (pino 2) não será usado
SoftwareSerial mySerial(7, 2); // RX, TX (TX não usado neste código)

// Inicialização do display LCD 16x2 via I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ajuste o endereço se necessário

String receivedData = ""; // String para armazenar os dados recebidos
int temperature = -1; // Variável para armazenar a temperatura (como inteiro)
String message = ""; // Variável para armazenar mensagens

// Array símbolo grau
byte grau[8] = {
  B00001100, //   ##
  B00010010, //  #  #
  B00010010, //  #  #
  B00001100, //   ##
  B00000000, //      
  B00000000, //      
  B00000000, //      
  B00000000  //      
};

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera para Arduinos com ATmega32u4 (USB Nativa)
  }
  Serial.println("Aguarde pelos dados.");
  mySerial.begin(4800); // Inicializa a comunicação com o módulo receptor

  // Inicializa o display LCD
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
  
  // Cria o caractere de grau
  lcd.createChar(0, grau); // Armazena o caractere na posição 0
  lcd.setCursor(0, 0);
  lcd.print("Temp: --"); // Texto inicial
}

void loop() {
  // Verifica se há dados disponíveis no receptor
  while (mySerial.available()) {
    char receivedChar = mySerial.read(); // Lê um caractere do receptor
    receivedData += receivedChar; // Adiciona o caractere à string

    // Verifica se o caractere é o delimitador de fim de mensagem
    if (receivedChar == '\n') {
      // Remove o caractere de nova linha no final
      receivedData.trim(); // Remove espaços em branco no início e no fim

      // Mensagem de depuração
      Serial.print("Received Data: ");
      Serial.println(receivedData); // Verifique o que está sendo recebido

      // Tenta converter o valor recebido para temperatura
      int tempValue = receivedData.toInt(); // Converte para inteiro

      // Verifica se o valor recebido é numérico
      if (tempValue != 0 || receivedData == "0") {
        // Atualiza a temperatura
        temperature = tempValue; // Atualiza a temperatura
        lcd.setCursor(0, 0); // Posiciona no início da primeira linha
        lcd.print("Temp: ");
        lcd.print(temperature); // Exibe como inteiro
        lcd.write(byte(0)); // Exibe o caractere de grau
        lcd.print("C     "); // Limpa espaços extras no LCD
      } else {
        // Se não for temperatura, trata como mensagem de texto
        message = receivedData; // Armazena a mensagem recebida
        lcd.setCursor(0, 1); // Exibe a mensagem na segunda linha
        lcd.print(message);
        lcd.print("                "); // Limpa espaços extras no LCD
      }

      // Limpa a string para novos dados
      receivedData = ""; 

      // Atraso para permitir a atualização do display
      delay(100);
    }
  }
}
