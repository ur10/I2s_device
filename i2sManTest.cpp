#if 1

#include "main.hpp"
#include "soundMan.hpp"

esp_err_t       cb_function(uint8_t* ip_bfr);

extern "C"{
  void app_main();
}



void app_main()
{
    soundMan smgr;
    smgr.attach_receive_cb(cb_function);
    smgr.init();

    // Tasks:
    // TODO: Define cb function.To do whatever with the data.
    // TODO: Test the Data.


}

#endif