#ifndef WIFI_SNIFFER_H
#define WIFI_SNIFFER_H

#include <WiFi.h>
#include "config.h"

bool analyzeTargetNetwork(String& ssid, int& rssi);

#endif
