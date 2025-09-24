// Ejemplo de loop FOR
// Encender y apagar un LED 5 veces

int ledPin = 2; // Pin del LED (GPIO2 del ESP32)

void setup() {
  pinMode(ledPin, OUTPUT); // Configurar pin como salida
  Serial.begin(115200);    // Comunicación serial
}

void loop() {
  // Repetir 5 veces
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin, HIGH); // Encender LED
    Serial.println("LED encendido");
    delay(500);

    digitalWrite(ledPin, LOW);  // Apagar LED
    Serial.println("LED apagado");
    delay(500);
  }

  // Esperar 2 segundos antes de repetir
  delay(2000);
}
