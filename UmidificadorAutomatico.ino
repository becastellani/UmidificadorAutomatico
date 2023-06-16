#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

//DHT
#define DHTTYPE DHT11 // Sensor DHT11
#define DHTPIN 9 // Pino do Arduino no Sensor (Data)
DHT_Unified dht(DHTPIN, DHTTYPE); // configurando o Sensor DHT - pino e tipo

uint32_t delayMS = 500; // variável para atraso no tempo
LiquidCrystal lcd(12, 11,5, 4, 3, 2);
int relayPin = 6;   
int chaveG = 7;
int umidadeLimite1 = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin(); // inicializa a função
  pinMode(relayPin, OUTPUT); 
  pinMode(chaveG, INPUT); //DEFINE A CHAVE GANGORRA
  digitalWrite(chaveG, HIGH);
}

void loop() {
  delay(delayMS); // atraso entre as medições
  sensors_event_t event; // inicializa o evento da Temperatura
    int chaveGState = digitalRead(chaveG);

    if (chaveGState == HIGH) {
      umidadeLimite1 = 65;
    } else {
      umidadeLimite1 = 20;
    }


dht.humidity().getEvent(&event); 
if (isnan(event.relative_humidity)) 
{ 
 Serial.println("Erro na leitura da Umidade!");
}else {
    if (event.relative_humidity <= umidadeLimite1) {
            Serial.print("Umidade: ");
            Serial.print(event.relative_humidity);
            Serial.println("%");
            lcd.setCursor(0, 0);
            lcd.print("Umidade:   ");
            lcd.print(event.relative_humidity);
            lcd.setCursor(0, 1);
            lcd.print("     Ligado     ");
            digitalWrite(relayPin, LOW);
    } 
    else {
            Serial.print("Umidade: ");
            Serial.print(event.relative_humidity);
            Serial.println("%");
            lcd.setCursor(0, 0);
            lcd.print("    Umidade     ");
            lcd.setCursor(0, 1);
            lcd.print("    Estavel     ");
            digitalWrite(relayPin, HIGH);
    }
  }
}
