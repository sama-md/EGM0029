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
#include <driver/gptimer.h>

void app_main(void)
{
    
    uint64_t count_value;
    
    gptimer_handle_t gptimer = NULL;
    gptimer_config_t timer_config = {
      .clk_src = GPTIMER_CLK_SRC_DEFAULT,
      .direction = GPTIMER_COUNT_UP,    
      .resolution_hz = 1 * 1000 * 1000,};
    gptimer_new_timer(&timer_config, &gptimer);
    gptimer_enable(gptimer);
    gptimer_start(gptimer);
    
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    
    for(;;){
       gptimer_get_raw_count(gptimer, &count_value);
    
       if (count_value > 1000000){ 
          gpio_set_level(GPIO_NUM_5, 1); 
       }
       else{                       
          gpio_set_level(GPIO_NUM_5, 0); 
       }
       
       if (count_value > 2000000){
          gptimer_set_raw_count(gptimer,0); 
       }
    }
}