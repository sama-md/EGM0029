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

volatile BaseType_t f_led=0;

void IRAM_ATTR button_isr();

void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);   

    gpio_set_direction(GPIO_NUM_10, GPIO_MODE_INPUT);         
    gpio_set_pull_mode(GPIO_NUM_10, GPIO_PULLUP_ENABLE);
    gpio_set_intr_type(GPIO_NUM_10, GPIO_INTR_LOW_LEVEL);
    
    gpio_install_isr_service(0);
    gpio_isr_handler_add(GPIO_NUM_10, button_isr, NULL);

    for(;;){
      gpio_set_level(GPIO_NUM_5, f_led); 
      vTaskDelay(100/portTICK_PERIOD_MS);
    }
}

void IRAM_ATTR button_isr()
{
    f_led ^= 1;
}