#include <WiFi.h>
#include "ThingSpeak.h"

// -------- Configuración WiFi --------
const char* ssid = "INCUBAGRARIA -1";
const char* password = "incuba062016";

// -------- Configuración ThingSpeak --------
unsigned long myChannelNumber = 2913045;    // Reemplaza con tu Channel ID
const char* myWriteAPIKey = "J2STDMLM2SL9ZNQV";         // Reemplaza con tu Write API Key

WiFiClient client;

// -------- Sensor de Humedad --------
#define SOIL_PIN 4   // Pin ADC donde está conectado el sensor

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  // Conexión WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Conectando a WiFi: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      delay(5000);
    }
    Serial.println("✅ Conectado a WiFi");
  }

  // Leer humedad del suelo
  int sensorValue = analogRead(SOIL_PIN); // Valor ADC (0 - 4095 en ESP32)
  int humedad = map(sensorValue, 4095, 1500, 0, 100); 
  // Ajusta "1500" según la calibración de tu sensor (valor en suelo mojado)

  if (humedad < 0) humedad = 0;
  if (humedad > 100) humedad = 100;

  Serial.print("Valor ADC: ");
  Serial.print(sensorValue);
  Serial.print(" -> Humedad: ");
  Serial.print(humedad);
  Serial.println("%");

  // Enviar a ThingSpeak (Field 1)
  ThingSpeak.setField(1, humedad);

  int statusCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if (statusCode == 200) {
    Serial.println("✅ Humedad enviada a ThingSpeak");
  } else {
    Serial.println("❌ Error enviando a ThingSpeak, código: " + String(statusCode));
  }

  delay(20000); // ThingSpeak requiere mínimo 15 segundos entre actualizaciones
}
