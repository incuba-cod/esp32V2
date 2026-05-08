#define SENSOR_PIN 34

int seco = 4095;
int mojado = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  int valor = analogRead(SENSOR_PIN);

  int humedad = map(valor, seco, mojado, 0, 100);

  humedad = constrain(humedad, 0, 100);

  Serial.print("ADC: ");
  Serial.print(valor);

  Serial.print(" | Humedad: ");
  Serial.print(humedad);
  Serial.println("%");

  delay(1000);
}
