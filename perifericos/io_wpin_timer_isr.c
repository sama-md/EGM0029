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
#include <esp_timer.h>

volatile BaseType_t f_led=0;

void IRAM_ATTR timer_isr(void *arg);

void app_main(void)
{
    const esp_timer_create_args_t timer_args = {
        .callback = &timer_isr,
        .name = "Timer"
    };
    esp_timer_handle_t timer_handler;

    esp_timer_create(&timer_args, &timer_handler);
    esp_timer_start_periodic(timer_handler, 1000000);

    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);

    for(;;){
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void IRAM_ATTR timer_isr(void *arg)
{
    gpio_set_level(GPIO_NUM_5, f_led);
    f_led ^= 1;
}