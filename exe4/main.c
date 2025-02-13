#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int red =5;
const int roxo = 8;
const int blue = 11;
const int yellow = 15;

const int botao = 28;

int main() {
  stdio_init_all();
  
  gpio_init(red);
  gpio_set_dir(red, GPIO_OUT);

  gpio_init(roxo);
  gpio_set_dir(roxo, GPIO_OUT);

  gpio_init(blue);
  gpio_set_dir(blue, GPIO_OUT);

  gpio_init(yellow);
  gpio_set_dir(yellow, GPIO_OUT);  
  
  gpio_init(botao);
  gpio_set_dir(botao, GPIO_IN);
  gpio_pull_up(botao);

  
  
  while (true) {
    // Use delay de 300 ms entre os estados!
    if(!gpio_get(botao)){
      gpio_put(red, 1);
      sleep_ms(300);
      gpio_put(red, 0);
      gpio_put(roxo, 1);
      sleep_ms(300);
      gpio_put(roxo, 0);
      gpio_put(blue, 1);
      sleep_ms(300);
      gpio_put(blue, 0);
      gpio_put(yellow, 1);
      sleep_ms(300);
      gpio_put(yellow, 0);
    }
  }
}
