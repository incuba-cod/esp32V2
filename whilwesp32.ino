// Ejemplo de loop WHILE
// Contar de 0 a 10

int contador = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  while (contador <= 10) {
    Serial.print("Contador: ");
    Serial.println(contador);
    contador++;
    delay(300);
  }

  // Reiniciar el contador para que vuelva a empezar
  contador = 0;
  delay(1000);
}
