#include <Servo.h>
Servo motor1; Servo motor2;
int sens = 5;
int posx = 0;
int posy = 0;
int bilgi;
void setup() 
{
  pinMode(5,INPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  motor1.attach(6);
  motor2.attach(3);
}

void loop()
{
  bilgi=digitalRead(5);

  if(bilgi == 1)
  {
    digitalWrite(6,HIGH);
    digitalWrite(3,LOW);
    
    for(posx = 0; posx <= 120; posx += 1)
    {
      motor1.write(posx);
      delay(30);
    }
    
    for(posx = 120; posx >=0; posx -= 1)
    {
      motor1.write(posx);
      delay(30);
    }
  }
  else
  {
    if(bilgi == 0){
    digitalWrite(3,HIGH);
    digitalWrite(6,LOW);
    motor2.write(60);
    delay(1000);
    motor2.write(0);
    delay(1000);
    }
  }
  


}
