#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_Vermelho = 28;
const int BTN_PIN_Verde = 26;
const int Led_vermelho = 4;
const int Led_verde = 6;

int main() {
  stdio_init_all();

  gpio_init(Led_vermelho);
  gpio_set_dir(Led_vermelho, GPIO_OUT);

  gpio_init(Led_verde);
  gpio_set_dir(Led_verde, GPIO_OUT);

  gpio_init(BTN_PIN_Vermelho);
  gpio_set_dir(BTN_PIN_Vermelho, GPIO_IN);
  gpio_pull_up(BTN_PIN_Vermelho);

  gpio_init(BTN_PIN_Verde);
  gpio_set_dir(BTN_PIN_Verde, GPIO_IN);
  gpio_pull_up(BTN_PIN_Verde);

  while (true) {
    if (!gpio_get(BTN_PIN_Vermelho)){
      if (gpio_get(Led_vermelho) == 1){
        gpio_put(Led_vermelho, 0);
        printf("Botão vermelho pressionado\n");
        while (!gpio_get(BTN_PIN_Vermelho)) {
        };
      } else {
        gpio_put(Led_vermelho, 1);
        printf("Botão vermelho pressionado\n");
        while (!gpio_get(BTN_PIN_Vermelho)) {
        }; 
      }
    }
    if (!gpio_get(BTN_PIN_Verde)){
      if (gpio_get(Led_verde) == 1){
        gpio_put(Led_verde, 0);
        printf("Botão verde pressionado\n");
        while (!gpio_get(BTN_PIN_Verde)) {
        };  
      } else {
        gpio_put(Led_verde, 1);
        printf("Botão verde pressionado\n");
        while (!gpio_get(BTN_PIN_Verde)) {
        };
      }
    }
  }
}
