#include <Arduino.h>
#include "oled_display.h"
#include "wifi_sniffer.h"

void setup() {
    Serial.begin(115200);
    initDisplay();
    WiFi.mode(WIFI_MODE_STA);
    WiFi.disconnect();
}

void loop() {
    String ssid;
    int rssi;

    // Анализ целевой сети
    if (analyzeTargetNetwork(ssid, rssi)) {
        Serial.printf("SSID: %s, RSSI: %d\n", ssid.c_str(), rssi);
    } else {
        Serial.println("Target network not found!");
    }

    // Обновляем дисплей
    updateGraph(ssid, rssi);

    delay(1000); // Обновляем каждую секунду
}
