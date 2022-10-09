#include "Wire.h"
#include <MPU6050_light.h>
#include <Servo.h>

MPU6050 mpu(Wire);
Servo servo1;
Servo servo2;
Servo servo3;
int X=0;
int x = 0;
int y = 0;
int z = 0;
int value  = 0;

unsigned long timer = 0;


void setup() {
  servo1.attach(14, 400, 2600);
  servo2.attach(12, 400, 2600);
  servo3.attach(13, 400, 2600);

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);

  Serial.begin(115200);
  Wire.begin();
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } // stop everything if could not connect to MPU6050
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(); // gyro and accelero
  X=mpu.getAccXoffset();/*{ return accXoffset; };
  float getAccYoffset(){ return accYoffset; };
  float getAccZoffset(){ return accZoffset; };*/
  Serial.println("Done!\n");
  
  

}
void loop() {

  mpu.update();
    //if ((millis() - timer) > 10) { // print data every 10ms
    x = mpu.getAngleX();
    y = mpu.getAngleY();
    z = mpu.getAngleZ();
    Serial.print("X : ");
    Serial.print(mpu.getAngleX());
    Serial.print(X);
    Serial.print("\tY : ");
    Serial.print(mpu.getAngleY());
    Serial.print("\tZ : ");
    Serial.println(mpu.getAngleZ());
    

if (x>-85 && x< 85){

   
      value = map(x,  -80, 85, 0, 180);
      Serial.println(value);
      servo1.write(value);
}     
if (y>-85 && y< 85){

   
      value = map(y,  -80, 85, 0, 180);
      Serial.println(value);
      servo2.write(value);
}      
    if (z>-85 && z< 85){

   
      value = map(z,  85, -85, 0, 180);
      Serial.println(value);
      servo3.write(value);
}      
    }