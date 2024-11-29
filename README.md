# one_network_analyzer
# Wi-Fi Analyzer for ESP32 with OLED Display

![Project](https://img.shields.io/badge/platform-PlatformIO-blue)  
![Board](https://img.shields.io/badge/board-ESP32--WROOM32-orange)  
![OLED](https://img.shields.io/badge/display-OLED%20I2C-green)  

## **Проект Wi-Fi Analyzer**

### **Описание**
Wi-Fi Analyzer — это проект, разработанный на основе микроконтроллера **ESP32 WROOM-32** и OLED-дисплея, подключенного по I2C.  
Проект анализирует Wi-Fi сеть, отображает её SSID (имя сети) и мощность сигнала (RSSI) в реальном времени на экране.

### **Основные возможности**
1. **Wi-Fi Sniffing**:
   - Отображение SSID доступных сетей Wi-Fi.
   - Отображение мощности сигнала каждой сети (RSSI).
   - Поддержка вывода до 5-6 сетей на экран одновременно.

2. **Графический интерфейс**:
   - Данные отображаются на OLED-дисплее (разрешение 128x64) в удобном формате.
   - Для Wi-Fi используется столбчатая диаграмма.

---

### **Технические требования**
- **Плата:** ESP32-WROOM-32
- **Дисплей:** OLED 128x64 с интерфейсом I2C (например, SSD1306)
- **Среда разработки:** Visual Studio Code с установленным **PlatformIO**.
- **Библиотеки:**
  - [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
  - [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

---

### **Как запустить проект**

1. Установите **Visual Studio Code** и плагин **PlatformIO**.  
   [Скачать VS Code](https://code.visualstudio.com/) | [Документация PlatformIO](https://platformio.org/platformio-ide)

2. Подключите ESP32 и настройте PlatformIO:  
   В `platformio.ini` указаны следующие параметры:
   ```ini
    [env:upesy_wroom]
    platform = espressif32
    board = upesy_wroom
    framework = arduino
    upload_port = COM4
    monitor_speed = 115200
    lib_deps =
        adafruit/Adafruit GFX Library
        adafruit/Adafruit SSD1306
        adafruit/Adafruit BusIO       
   
   
3.  - **Сканирование Wi-Fi сети.**
    - **Отображение SSID и мощности сигнала (RSSI).**
    - **OLED-дисплей (I2C).**

