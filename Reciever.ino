#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8); // CE, CSN

int fm_left1 = 11;
int fm_left2 = 12;
int fm_ryt1 = 9;
int fm_ryt2 = 10;

int bm_left1 = 2;
int bm_left2 = 3;
int bm_ryt1 = 4;
int bm_ryt2 = 5;

char comm;

const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {  
    radio.read(&comm, sizeof(comm));
    
    if(comm=='f'){
      analogWrite(fm_left1,255);
      analogWrite(fm_left2,0);
      analogWrite(fm_ryt1,255);
      analogWrite(fm_ryt2,0);

      analogWrite(bm_left1,255);
      analogWrite(bm_left2,0);
      analogWrite(bm_ryt1,255);
      analogWrite(bm_ryt2,0);
    }

    if(comm=='b'){
      analogWrite(fm_left1,0);
      analogWrite(fm_left2,255);
      analogWrite(fm_ryt1,0);
      analogWrite(fm_ryt2,255);

      analogWrite(bm_left1,0);
      analogWrite(bm_left2,255);
      analogWrite(bm_ryt1,0);
      analogWrite(bm_ryt2,255);
    }

   if(comm=='r'){
      analogWrite(fm_left1,255);
      analogWrite(fm_left2,0);
      analogWrite(fm_ryt1,0);
      analogWrite(fm_ryt2,255);

      analogWrite(bm_left1,255);
      analogWrite(bm_left2,0);
      analogWrite(bm_ryt1,0);
      analogWrite(bm_ryt2,255);
    }

    if(comm=='l'){
      analogWrite(fm_left1,0);
      analogWrite(fm_left2,255);
      analogWrite(fm_ryt1,255);
      analogWrite(fm_ryt2,0);

      analogWrite(bm_left1,0);
      analogWrite(bm_left2,255);
      analogWrite(bm_ryt1,255);
      analogWrite(bm_ryt2,0);
    }

    if(comm=='s'){
      analogWrite(fm_left1,0);
      analogWrite(fm_left2,0);
      analogWrite(fm_ryt1,0);
      analogWrite(fm_ryt2,0);

      analogWrite(bm_left1,0);
      analogWrite(bm_left2,0);
      analogWrite(bm_ryt1,0);
      analogWrite(bm_ryt2,0);
    }
  }
}
