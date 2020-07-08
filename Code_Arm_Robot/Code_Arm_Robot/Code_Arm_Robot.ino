#include <Servo.h>

float X;
float Y;
float t1;
float t2;
float t;
float L1 = 10; // cm
float L2 = 10; //cm

Servo myservo1;
Servo myservo2;

void setup() {
  Serial.begin(9600);
  myservo1.attach(7);
  myservo2.attach(8);

  Serial.println("Inpot (F) = Forward Kinematic");
  Serial.print("Inpot (I) = Inerse Kinematic");
  
}

void loop() {
  char x=Serial.read();
  delay(500);
  if (x == 'F')
  {
    // do Thing  Forward Kinematic
    Serial.println("Inpot (t1) = Angle link 1");
    t1 = Serial.parseFloat();
    delay(500);
    Serial.println(  "Inpot (t2) = Angle link 2");
    t2 = Serial.parseFloat();
        
    X = L1 * cos(t1) + L2 * cos(t1 + t2);
    Y = L1 * sin(t1) + L2 * sin(t1 + t2);
    
    myservo1.write(t1);
    myservo2.write(t2);
    
    Serial.print("X = ");Serial.println(X);
    Serial.print("Y = ");Serial.println(Y);

    delay(15);
  }
  else if (x == 'I')
  {
    // do Thing Inerse Kinematic
    Serial.println("Inpot (X) = X-dirction");
    X = Serial.parseFloat();
    delay(100);
    Serial.println( "Inpot (Y) = Y-dirction");
    Y = Serial.parseFloat();
    
    float cost2 = (pow(X, 2) + pow(Y, 2) - pow(L1, 2) - pow(L2, 2)) / (2 * L1 * L2);
    t2 = acos(cost2);
    t = sqrt(pow(X, 2) + pow(Y, 2));
    t1=t-t2;

    myservo1.write(t1);
    myservo2.write(t2);
    
    Serial.print("t1 = ");Serial.println(t1);
    Serial.print("t2 = ");Serial.println(t2);

    delay(15);
    
  }
  else
  {
    // do Thing Erorr
    Serial.println("Erorr in Inpot");
    delay(15);
  }
}
