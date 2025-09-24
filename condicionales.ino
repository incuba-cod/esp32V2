/*************************************************
 * EJEMPLO 03: IF (Condicionales)
 * Objetivo: Tomar decisiones con if.
 *************************************************/

int valor = 7; // Cambia este valor y observa el resultado

void setup() {
  Serial.begin(115200);
  Serial.println("=== EJEMPLO IF ===");

  // Evaluamos si valor es mayor a 5
  if (valor > 5) {
    Serial.println("El valor es mayor que 5");
  } else {
    Serial.println("El valor es menor o igual a 5");
  }
}

void loop() {
  // Aquí no hacemos nada, solo usamos el setup()
}


void loop() {
  // En este ejemplo no repetimos nada
}
