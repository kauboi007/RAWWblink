#include <Arduino.h>

#define GPIO_OUT_REG          0x3FF44004
#define GPIO_OUT_W1TS_REG     0x3FF44008
#define GPIO_OUT_W1TC_REG     0x3FF4400C
#define GPIO_ENABLE_REG       0x3FF44020
#define GPIO_ENABLE_W1TS_REG  0x3FF44024
#define GPIO_ENABLE_W1TC_REG  0x3FF44028

#define REG(addr) (*(volatile uint32_t*)(addr))

void cdigitalwrite(int pin,int mode){
  if(mode==1){
    //high
    REG(GPIO_OUT_W1TS_REG)=(1<<pin);
  }
  else if(mode==0){
    //low
    REG(GPIO_OUT_W1TC_REG)=(1<<pin);
  }
}

void cpinmode(int pin,int mode){
  if(mode==1){
    //output
    REG(GPIO_ENABLE_W1TS_REG)=(1<<pin);
  }
  else if(mode==0){
    //input
    REG(GPIO_ENABLE_W1TC_REG)=(1<<pin);
  }
}

void cdelay(){
  for(volatile int i=0;i<5000000;i++){

  }
}

void setup() {
  cpinmode(2,1);
}

void loop() {
  cdigitalwrite(2,1);
  cdelay();
  cdigitalwrite(2,0);
  cdelay();
}

