if 1

#include "main.hpp"
#include "soundMan.hpp"

  char string[] ="HERE GOES NOTHING";

esp_err_t       cb_function(uint16_t* ip_bfr,uint16_t len;

extern "C"{
  void app_main();
}


void app_main()
{
  uint16_t *data= (uint16_t*)malloc(sizeof(uint16_t)*80)  //buffer of sufficient length
  uint16_t length;
    soundMan smgr;
     smgr.init();    
    smgr.attach_transmit_cb(cb_function);//attaching the custom call back function
    smgr.tx_audio(&data,length); // txing 

    // Tasks:
    // TODO: Define cb function.To do whatever with the data.
    // TODO: Test the Data.


}
esp_err_t cb_function(uint16_t* ip_buffer,uint16_t len)
{
    /*
    we could test a .wav file but that would require SD card functionality,
    transmitting a simple text msg.
    */
   len = sizeof(string)*2; 
   ip_buffer = (uint16_t*)&string;
    
}


#endif
