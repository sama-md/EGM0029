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
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c_master.h"

uint8_t bcd2dec(uint8_t val);

void app_main() {

	struct tm time;
  static i2c_master_bus_handle_t master_bus_handle;
  static i2c_master_dev_handle_t master_dev_handle;
  uint8_t buf[7];
  uint8_t buffer[1] = {0x00}; 

  printf("RTC DS1307\n");

  i2c_master_bus_config_t i2c_bus_config = {
        .clk_source  = I2C_CLK_SRC_DEFAULT,
        .i2c_port    = I2C_NUM_0,
        .sda_io_num  = GPIO_NUM_8,
        .scl_io_num  = GPIO_NUM_9,
        .glitch_ignore_cnt = 7,
  };
  i2c_new_master_bus(&i2c_bus_config, &master_bus_handle);

  i2c_device_config_t dev_cfg = {
        .dev_addr_length    = I2C_ADDR_BIT_LEN_7,
        .device_address     = 0x68,
        .scl_speed_hz       = 100000,
  };
  i2c_master_bus_add_device(master_bus_handle, &dev_cfg, &master_dev_handle);

	TickType_t xLastWakeTime = xTaskGetTickCount();

	for(;;){

    i2c_master_transmit_receive(master_dev_handle, buffer, 1, buf, sizeof(buf), -1);

    time.tm_sec  = bcd2dec(buf[0] & 0x7f);
    time.tm_min  = bcd2dec(buf[1]);
    time.tm_hour = bcd2dec(buf[2] & 0x3f);
    time.tm_wday = bcd2dec(buf[3]) - 1;
    time.tm_mday = bcd2dec(buf[4]);
    time.tm_mon  = bcd2dec(buf[5]);
    time.tm_year = bcd2dec(buf[6]) + 2000;

    printf("%02d-%02d-%04d %02d:%02d:%02d\n", time.tm_mday, time.tm_mon, time.tm_year, time.tm_hour, time.tm_min, time.tm_sec);
	  vTaskDelayUntil(&xLastWakeTime, 100);
	}
}

uint8_t bcd2dec(uint8_t val)
{
    return (val >> 4) * 10 + (val & 0x0f);
}
