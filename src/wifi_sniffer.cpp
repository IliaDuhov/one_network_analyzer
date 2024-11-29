#include "wifi_sniffer.h"

bool analyzeTargetNetwork(String& ssid, int& rssi) {
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; i++) {
        if (WiFi.SSID(i) == TARGET_SSID) {
            ssid = WiFi.SSID(i);
            rssi = WiFi.RSSI(i);
            return true; // Сеть найдена
        }
    }
    ssid = "Not Found"; // Если сеть не найдена
    rssi = -100;        // Минимальное значение сигнала
    return false;
}
