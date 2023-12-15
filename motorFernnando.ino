#include <ESP8266_PWM.h>

const int motorPin = 0;

const int frectuencia 3000;

void setup() {
  pwm_begin();
  pwm_add(motorPin, frecuencia);
}

void loop() {
  pwm_set_duty(motorPin, 512);
  pwm_start();
}
