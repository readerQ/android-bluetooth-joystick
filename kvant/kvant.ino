#include <SoftwareSerial.h>// import the serial library
 
SoftwareSerial BT(11, 10); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
 
void setup() 
{
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  
  establishContact();  // send a byte to establish contact until receiver responds
  
  // put your setup code here, to run once:
  BT.begin(9600);
//  BT.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
  pinMode(12,OUTPUT);
}



void establishContact() {
blink();      
blink();      
blink();      

  
  while (Serial.available() <= 0) {
    Serial.println("0,0,0");   // send an initial string
    delay(300);
  }
}

 void blink()
 {
      digitalWrite(12,1);
      digitalWrite(ledpin,1);
      delay(300);
      digitalWrite(12,0);
      digitalWrite(ledpin,0);  
      delay(300);

  }


  int state = 1;
  int n = 0;
  
void loop() 
{

  // put your main code here, to run repeatedly:
  if (BT.available())
  {
    BluetoothData=BT.read();
    if (BluetoothData == 2)
    {
     int cnt=0; 
      while (cnt<5 ) //BT.available() && 
      {
        BluetoothData=BT.read();
        if (cnt<4)
        {
          Serial.print(BluetoothData);
          Serial.print(' ');
          }
          cnt++;
        } 
        
     }

 if (BluetoothData==3)
        {
          Serial.println(' ');
          Serial.println("joystick state");
          }
else
{
          Serial.println(' ');
          Serial.print("command ");
          Serial.println(BluetoothData);

          if (BluetoothData == 'A')
          {
           digitalWrite(12,1);
          }
          
          if (BluetoothData == 'B')
          {
           digitalWrite(12,0);
          }
 
  } 
        
    
  }


 delay(100); 
}
