#include <Arduino.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println();
  Serial.println("=== Test ESP32 ===");
  Serial.printf("Puce        : %s (rev %d)\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("Coeurs      : %d\n", ESP.getChipCores());
  Serial.printf("Frequence   : %d MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("Flash       : %u Ko\n", ESP.getFlashChipSize() / 1024);
  Serial.printf("RAM libre   : %u octets\n", ESP.getFreeHeap());
  Serial.printf("MAC         : %012llX\n", ESP.getEfuseMac());
  Serial.println("==================");
}

void loop() {
  static uint32_t compteur = 0;

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  Serial.printf("Tick %lu - uptime %lu s\n", (unsigned long)++compteur, millis() / 1000);
}
