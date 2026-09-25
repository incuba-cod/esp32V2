#include <WiFi.h>
#include <ThingSpeak.h>

// =============================
// WIFI
// =============================
const char* ssid = "WLAN_INVITADOS";
const char* password = "987654321";

// =============================
// THINGSPEAK
// =============================
unsigned long channelID = 3504436;

const char* readAPIKey = "MHBPJRSRASW7MM5F";

// =============================
// LED
// =============================
#define LED_PIN 2

WiFiClient client;

void setup() {

  Serial.begin(115200);

  // Configurar LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // =============================
  // CONECTAR WIFI
  // =============================

  WiFi.begin(ssid, password);

  Serial.print("Conectando a WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado");

  // Iniciar ThingSpeak
  ThingSpeak.begin(client);

  Serial.println("----------------------");
  Serial.println("Sistema iniciado");
  Serial.println("----------------------");
}

void loop() {

  // =============================
  // LEER FIELD 1
  // =============================

  int valor = ThingSpeak.readIntField(
    channelID,
    1,
    readAPIKey
  );

  Serial.print("Valor recibido: ");
  Serial.println(valor);

  // =============================
  // TOMAR DECISION
  // =============================

  if (valor == 1) {

    digitalWrite(LED_PIN, HIGH);

    Serial.println("LED ENCENDIDO");

  } else {

    digitalWrite(LED_PIN, LOW);

    Serial.println("LED APAGADO");
  }

  Serial.println("----------------------");

  delay(5000);
}
