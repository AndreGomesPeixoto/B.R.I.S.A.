#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configurações da tela OLED
#define LARGURA_TELA 128 // Largura do display em pixels
#define ALTURA_TELA 64   // Altura do display em pixels
#define PINO_RESET -1    // Pino de reset (-1 se compartilhar o reset do Arduino)
Adafruit_SSD1306 display(LARGURA_TELA, ALTURA_TELA, &Wire, PINO_RESET);

// Definição dos pinos
const int pinoSensor = A0;    // Pino analógico do sensor de ar
const int pinoVentilador = 8; // Pino digital do ventilador

// Limite aceitável de impureza (lembre-se de calibrar)
const int limiteImpureza = 400; 

void setup() {
  pinMode(pinoSensor, INPUT);
  pinMode(pinoVentilador, OUTPUT);
  Serial.begin(9600);
  digitalWrite(pinoVentilador, LOW); 

  // Inicializa o display OLED (o endereço 0x3C é o padrão para a maioria dessas telas)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao iniciar o display SSD1306"));
    for(;;); // Trava o código aqui se a tela não iniciar
  }

  // Limpa a tela e configura o texto
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println(F("Sistema Iniciado!"));
  display.display();
  delay(2000); // Mostra a mensagem de início por 2 segundos
}

void loop() {
  int nivelImpureza = analogRead(pinoSensor);
  
  // Limpa o display para a próxima atualização
  display.clearDisplay();
  display.setCursor(0, 0);

  // Lógica de controle e exibição na tela
  if (nivelImpureza > limiteImpureza) {
    digitalWrite(pinoVentilador, HIGH); // Liga o ventilador
    
    // Mostra alerta na tela
    display.setTextSize(2); // Texto maior para chamar atenção
    display.println(F("  ALERTA!"));
    display.setTextSize(1);
    display.println(F(""));
    display.println(F("Impureza detectada"));
    display.print(F("Nivel: "));
    display.println(nivelImpureza);
    display.println(F("Exaustor: LIGADO"));
    
  } else {
    digitalWrite(pinoVentilador, LOW);  // Desliga o ventilador
    
    // Mostra status normal na tela
    display.setTextSize(2);
    display.println(F(" AR LIMPO"));
    display.setTextSize(1);
    display.println(F(""));
    display.println(F("Tudo normal"));
    display.print(F("Nivel: "));
    display.println(nivelImpureza);
    display.println(F("Exaustor: DESLIGADO"));
  }

  // Envia as informações para a tela
  display.display(); 

  // Pausa antes da próxima leitura
  delay(500); 
}
