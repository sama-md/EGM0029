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
#include <driver/gpio.h>
#include "esp_adc/adc_oneshot.h"

adc_oneshot_unit_handle_t adc_handle;
static int valor_lido;

void app_main(void)
{  

    adc_oneshot_unit_init_cfg_t init_config = {.unit_id = ADC_UNIT_1};
    adc_oneshot_chan_cfg_t config = {.bitwidth = ADC_BITWIDTH_DEFAULT, 
                                     .atten    = ADC_ATTEN_DB_12};
    adc_oneshot_new_unit(&init_config, &adc_handle);                                     
    adc_oneshot_config_channel(adc_handle, ADC_CHANNEL_0, &config);

    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);

    for(;;){
        adc_oneshot_read(adc_handle, ADC_CHANNEL_0, &valor_lido);
        if (valor_lido > 2000){ 
           gpio_set_level(GPIO_NUM_5, 1); 
        }
        else{                
           gpio_set_level(GPIO_NUM_5, 0); 
        }
    }
}