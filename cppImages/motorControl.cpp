//cpp file for motor control for ball bot

#include <iostream>
#include <string>
#include <unistd.h>
#include "../include/SimpleGPIO.h"
using namespace std;

//pins
//motor controls
unsigned int m1F = 66; //pin P8_7  motor 1 +
unsigned int m1R = 67; //pin P8_8  motor 1 -
unsigned int m2F = 69; //pin P8_9  motor 2 +
unsigned int m2R = 68; //pin P8_10 motor 2 -

//functions
void forward(char power);
void reverse(char power);
void turnLeft(int deg);
void turnRight(int deg);
void stop();

int main(int argc, char *argv[]){
  //turn the gpio for out
  gpio_export(m1F);
  gpio_export(m1R);
  gpio_export(m2F);
  gpio_export(m2R);
  gpio_set_dir(m1F, OUTPUT_PIN);
  gpio_set_dir(m1R, OUTPUT_PIN);
  gpio_set_dir(m2F, OUTPUT_PIN);
  gpio_set_dir(m2R, OUTPUT_PIN);

  //end of prog stuff
  gpio_unexport(m1F); 
  gpio_unexport(m1R); 
  gpio_unexport(m2F); 
  gpio_unexport(m2R); 
}

//set the bot to move forward
void forward(char power){
    gpio_set_value(m1F,HIGH);
    gpio_set_value(m1R,LOW);
    gpio_set_value(m2F,HIGH);
    gpio_set_value(m2R,LOW);
}

//set the bot to move backward
void backward(char power){
    gpio_set_value(m1F,LOW);
    gpio_set_value(m1R,HIGH);
    gpio_set_value(m2F,LOW);
    gpio_set_value(m2R,HIGH);
}

//set the bot to turn right
void turnRight(int deg){
    gpio_set_value(m1F,HIGH);
    gpio_set_value(m1R,LOW);
    gpio_set_value(m2F,LOW);
    gpio_set_value(m2R,HIGH);
}

//set the bot to turn left
void turnLeft(int deg){
    gpio_set_value(m1F,LOW);
    gpio_set_value(m1R,HIGH);
    gpio_set_value(m2F,HIGH);
    gpio_set_value(m2R,LOW);
}

//stop the bot
void stop(){
    gpio_set_value(m1F,LOW);
    gpio_set_value(m1R,LOW);
    gpio_set_value(m2F,LOW);
    gpio_set_value(m2R,LOW);
}
