#include <AcceleroMMA7361.h>

AcceleroMMA7361 accelero;
int x;
int y;
int z;

void setup()
{
  Serial.begin(9600);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);                   //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);                   //sets the sensitivity to +/-6G
  accelero.calibrate();
}

void loop()
{
  x = accelero.getXAccel();
  y = accelero.getYAccel();
  z = accelero.getZAccel();
  
  
  
  float pitch = atan(x/sqrt(pow(y,2) + pow(z,2)));

  float roll = atan(y/sqrt(pow(x,2) + pow(z,2)));
 
 
  //convert radians into degrees

 pitch = pitch * (180.0/PI);

 roll = roll * (180.0/PI) ;
  
  
  
  Serial.print("\nx: ");
  Serial.print(x);
  Serial.print(" \ty: ");
  Serial.print(y);
  Serial.print(" \tz: ");
  Serial.print(z);
  Serial.print(" \t pitch: ");
  Serial.print(pitch);
  Serial.print(" \t roll: ");
  Serial.print(roll);
  
  
  if(pitch>40)
  {
    Serial.print("   left");
  }
  if(pitch<-40)
  {
    Serial.print("   right");
  }
  if(pitch>-40 && pitch<40)
  {
    Serial.print("   center");
  }
  
  if(roll>50)
  {
    Serial.print("----left");
  }
  if(roll<-50)
  {
    Serial.print("----right");
  }
  if(roll>-50 && roll<50)
  {
    Serial.print("----center");
  }
  
  
  //Serial.print("\tG*10^-2");
  delay(300);                                     //make it readable
}
