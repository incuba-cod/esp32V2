
#include <Wire.h>
#include <BH1750.h>

BH1750 sensor;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (sensor.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("Sensor listo");
  } else {
    Serial.println("Error al iniciar");
  }
}

void loop() {
  float lux = sensor.readLightLevel();
  Serial.print("Luz: ");
  Serial.print(lux);
  Serial.println(" lx");

  delay(1000);
}
