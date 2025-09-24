/*************************************************
 * EJEMPLO 04: LED + IF
 * Objetivo: Encender un LED si la variable es mayor que un valor.
 *************************************************/

#define LED_PIN 2    // Pin donde está conectado el LED
int valor = 3;       // Prueba cambiando este valor

void setup() {
  pinMode(LED_PIN, OUTPUT);   // Configurar pin como salida
  Serial.begin(115200);
}

void loop() {
  if (valor > 5) {
    digitalWrite(LED_PIN, HIGH); // Encender LED
    Serial.println("LED ENCENDIDO");
  } else {
    digitalWrite(LED_PIN, LOW);  // Apagar LED
    Serial.println("LED APAGADO");
  }
  
  delay(2000); // Espera 2 segundos antes de repetir
}
