#include <WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>

// -------- Configuración WiFi --------
const char* ssid = "INCUBAGRARIA -1";       // 🔹 Cambia por el nombre de tu red WiFi
const char* password = "incuba062016"; // 🔹 Cambia por tu contraseña WiFi

// -------- Configuración ThingSpeak --------
unsigned long myChannelNumber = 2913045;     // 🔹 Coloca el número de tu canal
const char* myWriteAPIKey = "J2STDMLM2SL9ZNQV";          // 🔹 Coloca tu API Key de escritura

WiFiClient client;

// -------- Configuración del sensor DHT22 --------
#define DHTPIN 4        // Pin GPIO donde está conectado el DHT22
#define DHTTYPE DHT22   // Tipo de sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.mode(WIFI_STA);

  ThingSpeak.begin(client); // Inicializar ThingSpeak
}

void loop() {
  // 🔹 Conectar WiFi si no está conectado
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Conectando a WiFi: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      delay(5000);
    }
    Serial.println("Conectado a WiFi!");
  }

  // 🔹 Leer datos del sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // 🔹 Verificar lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("❌ Error al leer el DHT22");
    delay(2000);
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");

  // 🔹 Enviar datos a ThingSpeak
  ThingSpeak.setField(1, t); // Temperatura en Field 1
  ThingSpeak.setField(2, h); // Humedad en Field 2

  int statusCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if (statusCode == 200) {
    Serial.println("✅ Datos enviados correctamente a ThingSpeak");
  } else {
    Serial.println("❌ Error enviando datos: " + String(statusCode));
  }

  delay(20000); // Esperar 20 segundos antes de volver a enviar
}
