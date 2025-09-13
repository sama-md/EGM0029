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

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <driver/gpio.h>

TimerHandle_t	timer;
BaseType_t f_led6 = 0;

static void vTaskTimer (TimerHandle_t xTimer);
static void vTask1( void *pvParameters );
static void vTask2( void *pvParameters );

void app_main() {

   gpio_set_direction(GPIO_NUM_6, GPIO_MODE_OUTPUT);
   timer = xTimerCreate("Timer", 200, pdTRUE, NULL, vTaskTimer);
   xTimerStart(timer, 0);
   xTaskCreatePinnedToCore( vTask1, "Task1", 2048, NULL, 1, NULL, 1);
   xTaskCreatePinnedToCore( vTask2, "Task2", 2048, NULL, 2, NULL, 1);
   for(;;);
}

static void vTaskTimer (TimerHandle_t xTimer)
{
   gpio_set_level(GPIO_NUM_6, f_led6);
   f_led6 ^= 1;
}

static void vTask1( void *pvParameters ){
   
   BaseType_t f_led5=0;

   gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
   
   for(;;){ 
      gpio_set_level(GPIO_NUM_5, f_led5);
      f_led5 ^= 1;
      vTaskDelay( 1000 / portTICK_PERIOD_MS );
   }
}

static void vTask2( void *pvParameters ){

   BaseType_t f_led4=0;

   gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
   
   for(;;){ 
      gpio_set_level(GPIO_NUM_4, f_led4);
      f_led4 ^= 1;
      vTaskDelay( 2000 / portTICK_PERIOD_MS );
   }
}
