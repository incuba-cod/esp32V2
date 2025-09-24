/*************************************************
 * EJEMPLO 02: VARIABLES
 * Objetivo: Entender qué es una variable y cómo usarla.
 *************************************************/

// Declaramos variables (cajitas donde guardamos datos)
int edad = 20;            // Variable entera
float temperatura = 23.5; // Número con decimales
String nombre = "Carlos"; // Texto (cadena)

void setup() {
  Serial.begin(115200); // Iniciar comunicación serial
  Serial.println("=== EJEMPLO VARIABLES ===");
  
  // Mostrar en pantalla el contenido de las variables
  Serial.print("Edad: ");
  Serial.println(edad);
  
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  Serial.print("Nombre: ");
  Serial.println(nombre);
}

void loop() {
  // En este ejemplo no repetimos nada
}
