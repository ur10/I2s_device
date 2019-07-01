#ifndef _MAIN_H_
#define _MAIN_H_

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "freertos/portmacro.h"

#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_err.h"
#include "esp_spiffs.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "tcpip_adapter.h"

#include "dns_server.hpp"
#include "captive_server.hpp"
#include "heap_monitor.hpp"

#endif