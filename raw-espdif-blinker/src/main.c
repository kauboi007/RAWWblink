#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    gpio_config_t io_config={
        .pin_bit_mask=(1ULL<<GPIO_NUM_2),
        .mode=GPIO_MODE_OUTPUT,
        .pull_up_en=GPIO_PULLUP_DISABLE,
        .pull_down_en=GPIO_PULLDOWN_DISABLE,
        .intr_type=GPIO_INTR_DISABLE
    };
    gpio_config(&io_config);
    while(1){
        gpio_set_level(GPIO_NUM_2,1);
        vTaskDelay(pdMS_TO_TICKS(1000));
        gpio_set_level(GPIO_NUM_2,0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }


}