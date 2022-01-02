#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial BT(2, 3); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
String dataRecv;
int Sipos[6];  // Store initial servo position
int Spos[6];   // Store current position
int flag = -1;
int SavePos[6][10];  //Save servo position
int n;

void sweep(Servo &theservo, int ipos, int pos)
{
if (pos>ipos)
{
  for(int i = ipos; i<=pos; i++)
  {
  theservo.write(i);
  Serial.println(i);
  delay(20);
  }
}
 else if(pos<ipos)
 for(int i = ipos; i>= pos; i--)
 {
  theservo.write(i);
  Serial.println(i);
  delay(20);
  }
  else if(pos==ipos)
    theservo.write(pos);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600); // baud rate of the HC-05 Bluetooth module
  BT.setTimeout(1);
  delay(30);
  Serial.println("Ready to connect\nDefault password is 1234 or 000"); 
  
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);

  Sipos[0] = 90;    
  Sipos[1] = 90;
  Sipos[2] = 90;
  Sipos[3] = 180;
  Sipos[4] = 180;
  Sipos[5] = 180;

  Spos[0] = 90;
  Spos[1] = 90;
  Spos[2] = 90;
  Spos[3] = 180;
  Spos[4] = 180;
  Spos[5] = 180;
  
  servo1.write(Sipos[0]);
  servo2.write(Sipos[1]);
  servo3.write(Sipos[2]);
  servo4.write(Sipos[3]);
  servo5.write(Sipos[4]);
  servo6.write(Sipos[5]);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available()>0)
  {
  digitalWrite(LED_BUILTIN, HIGH);
  dataRecv = BT.readString();
  //Serial.println(dataRecv);
    if(dataRecv.startsWith("s1"))
    {
      String data = dataRecv.substring(2,dataRecv.length());
      Spos[0] = data.toInt();
      Serial.println(data);
      sweep(servo1,Sipos[0],Spos[0]);
              Sipos[0] = Spos[0];
             }
    else if(dataRecv.startsWith("s2"))
    {
      String data = dataRecv.substring(2,dataRecv.length());
      Spos[1] = data.toInt();
      sweep(servo2,Sipos[1],Spos[1]);
      Sipos[1] = Spos[1];
     }
    else if(dataRecv.startsWith("s3"))
    {
      String data = dataRecv.substring(2,dataRecv.length());
      Spos[2] = data.toInt();
      sweep(servo3,Sipos[2],Spos[2]);
      Sipos[2] = Spos[2];
     }
    else if(dataRecv.startsWith("s4"))
    {
      String data = dataRecv.substring(2,dataRecv.length());
      Spos[3] = data.toInt();
      sweep(servo4,Sipos[3],Spos[3]);
      Sipos[3] = Spos[3];
     }
    else if(dataRecv.startsWith("s5"))
    {
      String data = dataRecv.substring(2,dataRecv.length());
      Spos[4] = data.toInt();
      sweep(servo5,Sipos[4],Spos[4]);
      Sipos[4] = Spos[4];
     }       
      else if(dataRecv.startsWith("s6"))
    {
      String data = dataRecv.substring(2,dataRecv.length());
      Spos[5] = data.toInt();
      sweep(servo6,Sipos[5],Spos[5]);
      Sipos[5] = Spos[5];
     }  
      else if(dataRecv.startsWith("save"))
      {
        flag = 1;
      }
      else if(dataRecv.startsWith("reset"))
      {
        flag = 0;
        n=0;
        Serial.println("RESET");
        }
      else if(dataRecv.startsWith("play"))
      {
        for(int i=n-1; i>=0; i--)
          {
           Serial.println("RUNNING SAVED MOVES:");
           Serial.print("MOVE NO : ");
           Serial.println(i);
            sweep(servo1,Sipos[0],SavePos[0][i]);
              Sipos[0] = SavePos[0][i];
            sweep(servo2,Sipos[1],SavePos[1][i]);
              Sipos[1] = SavePos[1][i];
            sweep(servo3,Sipos[2],SavePos[2][i]);
              Sipos[2] = SavePos[2][i];
            sweep(servo4,Sipos[3],SavePos[3][i]);
              Sipos[3] = SavePos[3][i];
            sweep(servo5,Sipos[4],SavePos[4][i]);
              Sipos[4] = SavePos[4][i];
            sweep(servo6,Sipos[5],SavePos[5][i]);
              Sipos[5] = SavePos[5][i];
            }
              for(int i=0; i<n; i++)
          {
           Serial.println("RUNNING SAVED MOVES:");
           Serial.print("MOVE NO : ");
           Serial.println(i);
            sweep(servo1,Sipos[0],SavePos[0][i]);
              Sipos[0] = SavePos[0][i];
            sweep(servo2,Sipos[1],SavePos[1][i]);
              Sipos[1] = SavePos[1][i];
            sweep(servo3,Sipos[2],SavePos[2][i]);
              Sipos[2] = SavePos[2][i];
            sweep(servo4,Sipos[3],SavePos[3][i]);
              Sipos[3] = SavePos[3][i];
            sweep(servo5,Sipos[4],SavePos[4][i]);
              Sipos[4] = SavePos[4][i];
            sweep(servo6,Sipos[5],SavePos[5][i]);
              Sipos[5] = SavePos[5][i];
            }
          flag = -1;
        }
       if (flag==1 && n<10)
       {
       SavePos[0][n] = Sipos[0];
       SavePos[1][n] = Sipos[1];
       SavePos[2][n] = Sipos[2];
       SavePos[3][n] = Sipos[3];
       SavePos[4][n] = Sipos[4];
       SavePos[5][n] = Sipos[5];
       n++; 
       Serial.println("SAVED");
       Serial.print("NO OF MOVES = ");
       Serial.println(n);
       flag = -1;
       }
        else if(n>=10)
        { 
          flag = -1;
          Serial.println("LIMITED EXCEEDED: MAXIMUM 10 MOVES ALLOWED");
          }
  }
  else // Blink LED when not connected
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
}
}
