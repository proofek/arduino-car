#include <IRremote.h>
#include <IRremoteInt.h>

int motor1DirPin = 4;
int motor2DirPin = 7;
int motor1SpeedPin = 5;
int motor2SpeedPin = 6;
int remotePin = 11;

IRrecv irrecv(remotePin);
decode_results results;


void setup()
{
  pinMode(motor1DirPin, OUTPUT);
  pinMode(motor2DirPin, OUTPUT);
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    
  if (results.value == 0xFDA05F)
  {
   forward(); 
   delay(500);
   stop();
  }
    if (results.value == 0xFDB04F)
  {
   backwards(); 
   delay(500);
   stop();
  }
    if (results.value == 0xFD10EF)
  {
   left(); 
   delay(500);
   stop();
  }
    if (results.value == 0xFD50AF)
  {
   right(); 
   delay(500);
   stop();
  }
  }
  

  /*
  forward(); 
  stop();
  left();
  stop();
  backwards();
  stop();
  right();
  stop();
  */
} 

void forward()
{
  Serial.println("forward");
  digitalWrite(motor1DirPin, HIGH);
  analogWrite(motor1SpeedPin, 255);
  digitalWrite(motor2DirPin, HIGH);
  analogWrite(motor2SpeedPin, 238);
}

void backwards()
{
  Serial.println("backwards");
  digitalWrite(motor1DirPin, LOW);
  analogWrite(motor1SpeedPin, 255);
  digitalWrite(motor2DirPin, LOW);
  analogWrite(motor2SpeedPin, 238);
}

void left()
{
  Serial.println("forward");
  digitalWrite(motor1DirPin, HIGH);
  analogWrite(motor1SpeedPin, 175);
  digitalWrite(motor2DirPin, LOW);
  analogWrite(motor2SpeedPin, 0);
}

void right()
{
  Serial.println("forward");
  digitalWrite(motor1DirPin, LOW);
  analogWrite(motor1SpeedPin, 0);
  digitalWrite(motor2DirPin, HIGH);
  analogWrite(motor2SpeedPin, 125);
}


void stop()
{
  digitalWrite(motor1SpeedPin, 0);
  digitalWrite(motor2SpeedPin, 0);
}
