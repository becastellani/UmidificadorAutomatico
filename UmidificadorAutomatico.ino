#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

//DHT
#define DHTTYPE DHT11 // Sensor DHT11
#define DHTPIN 9 // Pino do Arduino no Sensor (Data)
DHT_Unified dht(DHTPIN, DHTTYPE); // configurando o Sensor DHT - pino e tipo

uint32_t delayMS = 500; // variável para atraso no tempo
LiquidCrystal lcd(12, 11,5, 4, 3, 2); // VARIAVEIS E PINOS DO DISPLAY LCD
int relayPin = 6;   // VARIAVEL PINO DO RELAY
int chaveG = 7; //VARIAVEL PINO CHAVE GANGORRA
int umidadeLimite1 = 0; // VARIAVEL DEFINE O LIMITE DA UMIDADE INICIAL

void setup() {
  Serial.begin(9600); // INICIALIZA O MONITOR SERIAL
  lcd.begin(16, 2); // INICIAL O DISPLAY LCD
  dht.begin(); // INICIALIZA O SENSOR DHT11
  pinMode(relayPin, OUTPUT); 
  pinMode(chaveG, INPUT); //DEFINE A CHAVE GANGORRA
  digitalWrite(chaveG, HIGH);
}

void loop() {
  delay(delayMS); // atraso entre as medições
  sensors_event_t event; // inicializa o evento da Temperatura
   int chaveGState = digitalRead(chaveG);// LÊ A CHAVE GANGORRA

    if (chaveGState == HIGH) {
      umidadeLimite1 = 65;
    } else {
      umidadeLimite1 = 20;
    }   // DEFINE O VALOR DO LIMITE DE ACORDO COM 0 NIVEL(ALTO E BAIXO) DA CHAVE GANGORRA


dht.humidity().getEvent(&event); // CAPTA A UMIDADE DO AR ATRAVÉS DO SENSOR
if (isnan(event.relative_humidity)) // SE A UMIDADE DO AR NAO FOR LIDA
{ 
 Serial.println("Erro na leitura da Umidade!");
}else {
    if (event.relative_humidity <= umidadeLimite1) { // SE A UMIDADE DO AR FOR MENOR OU IGUAL AO LIMITE DEFINIDO PELA CHAVE GANGORRA
            Serial.print("Umidade: "); // PRINTA A FRASE NO MONITOR SERIAL
            Serial.print(event.relative_humidity); // PRINTA A UMIDADE NO MONITOR SERIAL
            Serial.println("%");//PRINTA O % NO MONITOR SERIAL
            lcd.setCursor(0, 0);  // SETA O PONTEIRO A PRIMEIRA LINHA DO DISPLAY
            lcd.print("Umidade:   "); // PRINTA UMIDADE NO DISPLAY LCD
            lcd.print(event.relative_humidity); //PRINTA O VALOR DA UMIDADE NO DISPLAY
            lcd.setCursor(0, 1);// SETA O PONTEIRO A SEGUNDA LINHA DO DISPLAY
            lcd.print("     Ligado     "); // PRINTA LIGADO NO DISPLAY LCD
            digitalWrite(relayPin, LOW); // DESLIGA O RELAY
    } 
    else { //CASO CONTRARIO, A UMIDADE É ESTAVEL
            Serial.print("Umidade: "); // PRINTA A FRASE NO MONITOR SERIAL
            Serial.print(event.relative_humidity); // PRINTA A UMIDADE NO MONITOR SERIAL
            Serial.println("%"); //PRINTA O % NO MONITOR SERIAL
            lcd.setCursor(0, 0); // SETA O PONTEIRO A PRIMEIRA LINHA DO DISPLAY
            lcd.print("    Umidade     "); // PRINTA UMIDADE NO DISPLAY LCD
            lcd.setCursor(0, 1); // SETA O PONTEIRO A SEGUNDA LINHA DO DISPLAY
            lcd.print("    Estavel     "); // PRINTA ESTAVEL NO DISPLAY LCD
            digitalWrite(relayPin, HIGH); // LIGA O RELAY
    }
  }
}
