
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
#endif

// CONFIG HANDLING
typedef struct{

i2s_port_t    device_port;     // port number of the device

i2s_channel_t device_channel    // mono or stereo channel

i2s_config_t  device_config; // speed, mode,  DMA buf len ,  APLL choice

i2s_event_t device_mode_data;  // mode , data len

i2_pin_config_t device_pin_config; //  pin config for the peripheral

}device_config_t;


// ERROR HANDLING
typedef enum{
    DEVICE_OK = 0x01;
    
    DEVICE_INIT_ERROR;
    

    DEVICE_RX_ERROR;
    
    DEVICE_TX_ERROR;
    
}device_error_t;

/*                                         APIs FOR THE DEVICE                                                                                 */



/*
@brief                             Set the pins for I2S, configure the sample rate and clock speed

@param device_config_t             Varioius configurations of the device like i2s_channel, mode,sample rate etc.

@ret_val device_error_t            DEVICE_OK - PROPERLY CONFIGURED      DEVICE_INIT_ERROR - ILLEGAL SET OF CONFIGURATIONS USEDEetc.

                                   
*/

device_error_t  device_configure (device_config_t *config );  // i2s_set_pin  i2s_set_sample_rate  i2s_set_clock

/*
@brief                        Set the I2S register with the chosen parameters , init the device.

@param  device_config_t       Varioius configurations of the device like i2s_channel, mode,sample rate etc.

@param queue_size             I2S event queue size/depth.

@param  queue                 I2S event queue handle, if set NULL, driver will not use an event queue.

@ret_val                      DEVICE_OK - PROPERLY CONFIGURED      DEVICE_INIT_ERROR - ILLEGAL SET OF CONFIGURATIONS USEDEetc.
*/


device_error_t   device_init (device_config_t config, int queue_size ,void *queue ) // i2s_driver_install i2s_start

/*
@brief                        Rxing the data of the device

@param  device_config_t       Varioius configurations of the device like i2s_channel, mode,sample rate etc.

@param  dest                   Memory adress of the buffer for rxing data

@param size                    Size of data in bytes

@param[out] bytes_read         Number of bytes read, if timeout, bytes read will be less than the size passed in.

@param ticks_to_wait           RX buffer wait timeout in RTOS ticks. If this many ticks pass without bytes becoming available in the DMA receive buffer, then the function will return (note that if data is read from the DMA buffer in pieces, the overall operation may still take longer than this timeout.) Pass portMAX_DELAY for no timeout. 

@ret_val                       DEVICE_OK - PROPERLY CONFIGURED      DEVICE_INIT_ERROR - ILLEGAL SET OF CONFIGURATIONS USEDEetc.
                               DVICE_TX_ERROR - ERRORS LIKE BYTES READ<SIZE.
*/
device_error_t  device_rxing( device_config_t *config , void *dest, size_t size, size_t *bytes_read, TickType_t ticks_to_wait)

/* */
//device_error_t  device_deinit(device_config_t *config );
