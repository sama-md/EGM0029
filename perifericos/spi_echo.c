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
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

void app_main(void) {

  spi_device_handle_t  SpiDeviceHandle;

  uint8_t TxData = 0x07;
  uint8_t RxData[2] = {0,0};

  spi_bus_config_t SpiBusConfig = {
    .mosi_io_num = GPIO_NUM_12, 
    .miso_io_num = GPIO_NUM_13,
    .sclk_io_num = GPIO_NUM_11,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
  };
  spi_bus_initialize(SPI2_HOST, &SpiBusConfig, SPI_DMA_CH_AUTO); 

  spi_device_interface_config_t SpiDeviceConfig = {
    .clock_speed_hz = 10000000,             
    .mode = 0,                                  
    .spics_io_num = GPIO_NUM_10,                
    .queue_size = 1,                            
  };
  spi_bus_add_device(SPI2_HOST, &SpiDeviceConfig, &SpiDeviceHandle);  

  spi_transaction_t SpiTransaction = {
    .cmd = 0,
    .addr = 0,
    .flags = SPI_TRANS_USE_TXDATA,                                  
    .tx_data = {TxData},                                        
    .tx_buffer = TxData, 
    .rx_buffer = RxData,
    .rxlength = 8,    
    .length = 8,                                                   
  };

  for(;;){
    printf("Enviado:'0x%x'\n", TxData);
    spi_device_polling_transmit(SpiDeviceHandle, &SpiTransaction);               
    vTaskDelay(1 / portTICK_PERIOD_MS);   
    uint8_t data = ((uint8_t*) RxData)[0];
    printf("Recebido: %d\n", data);
    vTaskDelay(pdMS_TO_TICKS(1000));
   }
}