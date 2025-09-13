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
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/message_buffer.h>
#include <driver/gpio.h>

#define BUFFER_SIZE 200
#define DATA_SIZE   10 

MessageBufferHandle_t xMessage;

static void vTask1( void *pvParameters );
static void vTask2( void *pvParameters );

void app_main() {

   xMessage = xMessageBufferCreate(BUFFER_SIZE);
   xTaskCreatePinnedToCore( vTask1, "Task1", 2048, NULL, 1, NULL, 1);
   xTaskCreatePinnedToCore( vTask2, "Task2", 2048, NULL, 2, NULL, 1);
   for(;;);
}

static void vTask1( void *pvParameters ){
   
   const char *message = "Hello, world!";
   size_t mlength = strlen(message) + 1; 
   BaseType_t xReturn;
   BaseType_t f_led5=0;

   gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
   
   for(;;){ 
      gpio_set_level(GPIO_NUM_5, f_led5);
      f_led5 ^= 1;
      xReturn = xMessageBufferSend(xMessage, message, mlength, portMAX_DELAY);
      vTaskDelay( 5000 / portTICK_PERIOD_MS );
   }
}

static void vTask2( void *pvParameters ){

   char buffer[DATA_SIZE + 1]; 
   size_t received;
   BaseType_t f_led4=0;

   gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
   
   for(;;){ 
      received = xMessageBufferReceive(xMessage, buffer, DATA_SIZE + 1, portMAX_DELAY);
      gpio_set_level(GPIO_NUM_4, f_led4);
      f_led4 ^= 1;
      vTaskDelay( 1000 / portTICK_PERIOD_MS );
   }
}