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
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"

#define BUF_SIZE (1024)

void app_main(void)
{
    
    uart_config_t uart_config = {
        .source_clk = UART_SCLK_DEFAULT,
        .baud_rate  = 9600,
        .data_bits  = UART_DATA_8_BITS,
        .parity     = UART_PARITY_DISABLE,
        .stop_bits  = UART_STOP_BITS_1,
        .flow_ctrl  = UART_HW_FLOWCTRL_DISABLE,
    };

    uart_driver_install(0, BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(0, &uart_config);
    uart_set_pin(0, GPIO_NUM_2, GPIO_NUM_3, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    uint8_t data[128];
    int len = 0;

    for(;;){
        len = uart_read_bytes(0, data, (BUF_SIZE - 1), 20/portTICK_PERIOD_MS);
        if (len) {
            data[len] = '\0';
            printf("Recebido: %s\n", (char *) data);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

