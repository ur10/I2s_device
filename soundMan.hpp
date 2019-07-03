#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

/* Includes */

#include "freertos/FreeRTOS.h"

// Drivers
#include "driver/i2s.h"


// System Includes
#include "esp_err.h"
#include "esp_log.h"

/* Defines */
#define soundManTag  "soundMan"
#define i2s_PORT_0   I2S_NUM_0
#define i2s_PORT_1   I2S_NUM_1

#define standard_MIC_SAMPLE_RATE 48000 //48Khz


class soundMan
{
    private:
        i2s_port_t       port;                  // port number of the device
        i2s_channel_t    channel;               // mono or stereo channel
        i2s_config_t     config;                // speed, mode,  DMA buf len ,  APLL choice
        i2s_pin_config_t pinout;                // pin config for the peripheral
        uint16_t*        input_bfr = NULL;             // input buffer for receive operations.
        int              round_sample_count = 0;       // no of samples in each round of rx_audio().
        esp_err_t       (*post_receive_callback)(uint16_t* ip_bfr, uint16_t sample_len);    // The attached function will receive the I2S received buffer as a param.
        esp_err_t       (*post_transmit_callback)(uint16_t* op_bfr, uint16_t sample_len);

    public:
        soundMan();                             // Default Constructor for soundMan.               
        soundMan(i2s_port_t port,               // Custom Constructor for SoundMan.
                 i2s_channel_t channel,
                 i2s_config_t config,
                 i2s_pin_config_t pinout);
        esp_err_t init();                                 // Initialiser
        // uint8_t*  push_input_buffer();                    // Returns the input buffer which 
        // uint8_t*  push_output_buffer();
        esp_err_t rx_audio();                             // Start Receiving
        esp_err_t tx_audio(uint16_t* op_bfr, uint16_t sample_len);          // Start Transmitting
        esp_err_t attach_receive_cb(esp_err_t (*function)(uint16_t* ip_bfr, uint16_t sample_len));
        esp_err_t attach_transmit_cb(esp_err_t (*function)(uint16_t* ip_bfr, uint16_t sample_len));
};

#endif /* @ _SOUND_MANAGER_H_ */