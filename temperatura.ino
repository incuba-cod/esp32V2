#include <Wire.h>
#include <Adafruit_SHT4x.h>

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!sht4.begin()) {
    Serial.println("No se encontró SHT40");
    while (1);
  }

  Serial.println("SHT40 listo");
}

void loop() {
  sensors_event_t humidity, temp;
  sht4.getEvent(&humidity, &temp);

  Serial.print("Temp: ");
  Serial.print(temp.temperature);
  Serial.print(" °C  | Humedad: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  delay(2000);
}