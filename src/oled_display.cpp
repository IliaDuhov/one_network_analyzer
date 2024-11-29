#include "oled_display.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);


static int rssiHistory[GRAPH_WIDTH] = {0};

void initDisplay() {
    Wire.begin(OLED_SDA, OLED_SCL);
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("OLED init failed!");
        ESP.restart();
    }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.display();
}

void updateGraph(const String& ssid, int rssi) {
    // Обновляем историю значений RSSI
    for (int i = 0; i < GRAPH_WIDTH - 1; i++) {
        rssiHistory[i] = rssiHistory[i + 1];
    }
    rssiHistory[GRAPH_WIDTH - 1] = map(rssi, -100, -30, 0, GRAPH_HEIGHT);
    rssiHistory[GRAPH_WIDTH - 1] = constrain(rssiHistory[GRAPH_WIDTH - 1], 0, GRAPH_HEIGHT);

    // Очистка дисплея
    display.clearDisplay();

    // Вывод SSID
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("SSID:");
    display.setCursor(40, 0);
    display.print(ssid);

    // Рисуем ось графика
    display.drawLine(0, GRAPH_BASELINE, GRAPH_WIDTH, GRAPH_BASELINE, WHITE);

    // Рисуем график
    for (int i = 0; i < GRAPH_WIDTH - 1; i++) {
        int y1 = GRAPH_BASELINE - rssiHistory[i];
        int y2 = GRAPH_BASELINE - rssiHistory[i + 1];
        display.drawLine(i, y1, i + 1, y2, WHITE);
    }

    // Отображаем RSSI числом
    display.setCursor(0, GRAPH_BASELINE + 10);
    display.printf("RSSI: %d dBm", rssi);

    // Отображаем всё на дисплее
    display.display();
}
