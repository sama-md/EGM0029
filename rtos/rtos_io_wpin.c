//
// Copyright (C) 2025 Samaherni M. D.
// Universidade Federal do Rio Grande do Norte (UFRN)
// 
// This file is part of EGM0029 project (https://github.com/sama-md/EGM0029/). 
// It is subject to the license terms in the LICENSE file found in the top-level 
// directory of this distribution. 
//
// Licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 
// 4.0 International License;
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  (EN)  https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode
//  (PT)  https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.pt
//
// Unless otherwise separately undertaken by the Licensor, to the extent possible, 
// the Licensor offers the Licensed Material "as-is" and "as-available", and makes
// no representations or warranties of any kind concerning the Licensed Material, 
// whether express, implied, statutory, or other.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

void vTasknull(void *pvParameter);
void vTaskiowpin(void *pvParameter);

void app_main()
{
    xTaskCreatePinnedToCore(&vTasknull  , "null_task", 1024, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(&vTaskiowpin, "blink_led", 1024, NULL, 1, NULL, 0);
}

void vTasknull(void *pvParameter)
{
    for(;;){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void vTaskiowpin(void *pvParameter)
{
    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
    BaseType_t f_led=0

    for(;;){
        gpio_set_level(GPIO_NUM_5, f_led);
        f_led ^= 1;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}