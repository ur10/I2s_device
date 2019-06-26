
#ifndef _DRIVER_I2S_H_
#define _DRIVER_I2S_H_

#include "esp_err.h"
#include <esp_types.h>
#include "soc/gpio_reg.h"
#include "soc/soc.h"
#include "soc/i2s_struct.h"
#include "soc/i2s_reg.h"
#include "soc/rtc_io_reg.h"
#include "soc/io_mux_reg.h"
#include "rom/gpio.h"
#include "esp_attr.h"
#include "esp_intr_alloc.h"
#include "driver/periph_ctrl.h"
#include "driver/adc.h"
#include "freertos/semphr.h"
#include "i2s.h"
#include "I2S_driver.h"
#endif

/*Device configuration API */
device_error_t  device_configure (device_config_t *config ) 
{
    // PIN CONFIG SETTINGS
  if(esp_err_t i2s_set_pin(config->device_port, config->device_pin_config)==ESP_OK)
  {
      ESP_LOGD(TAG,"Pin configurations set succesfully");
  }
  
  if(esp_err_t i2s_set_pin(config->device_port, config->device_pin_config)==ESP_ERR_INVALID_ARG)
  {
      ESP_LOGD(TAG,"Illegal pin configs passed");

  }

  // SAMPLE RATE SETTINGS
  if(esp_err_t i2s_set_sample_rates(config->device_port, config->device_config.sample_rate)==ESP_OK)
  {
      ESP_LOGD(TAG,"Device initialized with sampling rate : %d",config->device_config.sample_rate);
  }

  if(esp_err_t i2s_set_sample_rates(config->device_port, config->device_config.sample_rate)==ESP_ERR_INVALID_ARG)
  {
    ESP_LOGD(TAG,"Illegal sample rate configs passed"); 

    
      return DEVICE_INIT_ERROR;
  }

  //CLOCK INITIALIZATION OF THE PERIPHERAL
  if(esp_err_t i2s_set_clk(config->device_port, config->device_config.sample_rate, config->device_config.bits_per_sample_t, config->device_channel)==ESP_OK)
  {
        ESP_LOGD(TAG," Peripheral Clock initialized");
       
  }    
 
  if(esp_err_t i2s_set_clk(config->device_port, config->device_config.sample_rate, config->device_config.bits_per_sample_t, config->device_channel)==Esp_ERR_INVALID_ARG)
   {
       ESP_LOGD(TAG,"Illegal clock configurations passed");
   
      return DEVICE_INIT_ERROR;
   }
 
 
 }


/*Device Init API*/
device_error_t   device_init (device_config_t *config, int queue_size ,void *queue )  //i2s_driver_install i2s_start
{
  // Set(install) the registers of the driver peripheral
 if(esp_err_t i2s_driver_install(config->device_port, config->device_config, queue_size,  i2s_queue)==ESP_OK)
 {
     ESP_LOGD(TAG,"Peripheral driver Installed");
 }
 if(esp_err_t i2s_driver_install(config->device_port, config->device_config, queue_size,  i2s_queue)==ESP_ERR_INVALID_ARG)
 {
     ESP_LOGD(TAG,"Illegal arguments passed");

     return DEVICE_INIT_ERROR;
 }

 // Start the I2S device
 if( esp_err_t i2s_start(config->device_port )== ESP_OK )
 {
    ESP_LOGD(TAG,"DEVICE HAS SATRTED SUCCESSFULLY");
 } 
 if(esp_err_t i2s_start(config->device_port)==ESP_ERR_INVALID)
 {
    ESP_LOGD(TAG,"Unable to start successfully");
  
    return DEVICE_INIT_ERROR;
 }

}