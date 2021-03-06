#include <AcceleroMMA7361.h>

AcceleroMMA7361 accelero;
int x;
int y;
int z;

void setup()
{
  Serial.begin(115200);
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
 
 
 
 int orien=0;
 
 if(roll>40)
  {
    orien=350;
  }
  if(roll<-40)
  {
    orien=650;
  }
  if(roll>-40 && pitch<40)
  {
    orien=500;
  }
  
  
  
  
  
  Serial.print(orien);
  Serial.println(" ");
  
  Serial.print(orien);
  Serial.println(" ");
  /*
  Serial.print(y);
  Serial.println(" ");
  Serial.print(z);
  Serial.println(" ");
 */
  
  
  
                                     //make it readable
}
