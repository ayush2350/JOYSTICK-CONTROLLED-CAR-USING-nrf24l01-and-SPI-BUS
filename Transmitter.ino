#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 9); // CE, CSN

int fm_left1 = 11;
int fm_left2 = 12;
int fm_ryt1 = 9;
int fm_ryt2 = 10;

int bm_left1 = 2;
int bm_left2 = 3;
int bm_ryt1 = 4;
int bm_ryt2 = 5;

// Joystick Connection pins
int Xpin = A1;
int Ypin = A0;
int Xval, Yval;
char comm;

const byte address[6] = "00001";
void setup() {
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  Xval= analogRead(Xpin);
  Yval= analogRead(Ypin);

// STOP
  if((Xval>=540 && Xval<=548) && (Yval>=515 && Yval<=523)){
    comm = 's';
    radio.write(&comm, sizeof(comm));
    Serial.println(comm);
  }

// Forward  
  if((Xval>=540 && Xval<=548) && (Yval>=524 && Yval<=1023)){
    comm = 'f';
    radio.write(&comm, sizeof(comm));
    Serial.println(comm);
  }  

// Backward  
  if((Xval>=540 && Xval<=548) && (Yval>=0 && Yval<=514)){
    comm = 'b';
    radio.write(&comm, sizeof(comm));
    Serial.println(comm);
  }  

// Right  
  if((Xval>=0 && Xval<=539) && (Yval>=515 && Yval<=523)){
    comm = 'r';
    radio.write(&comm, sizeof(comm));
    Serial.println(comm);
  }   

// Left
  if((Xval>=549 && Xval<=1023) && (Yval>=515 && Yval<=523)){
    comm = 'l';
    radio.write(&comm, sizeof(comm));
    Serial.println(comm);
  }  
}
