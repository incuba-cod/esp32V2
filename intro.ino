/*************************************************
 * EJEMPLO 01: SETUP Y LOOP
 * Objetivo: Entender qué hacen setup() y loop().
 *************************************************/

void setup() {
  // Esto se ejecuta solo una vez al inicio
  Serial.begin(115200);
  Serial.println("El programa ha iniciado (setup)");
}

void loop() {
  // Esto se repite una y otra vez sin parar
  Serial.println("Estoy dentro del loop...");
  delay(1000); // Espera 1 segundo antes de repetir
}

  // En este ejemplo no repetimos nada
}
