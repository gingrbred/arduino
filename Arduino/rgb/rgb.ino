/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redpin = 13;
int greenpin = 12;
int bluepin = 11;
int redpin2 = 10;
int greenpin2 = 9;
int bluepin2 = 8;
int redpin3 = 7;
int greenpin3 = 6;
int bluepin3 = 5;

//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

void setup()
{
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(redpin2, OUTPUT);
  pinMode(greenpin2, OUTPUT);
  pinMode(bluepin2, OUTPUT);
  pinMode(redpin3, OUTPUT);
  pinMode(greenpin3, OUTPUT);
  pinMode(bluepin3, OUTPUT);
}

void loop()
{
  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redpin, red);
  analogWrite(greenpin, green);
  analogWrite(bluepin, blue);
  analogWrite(redpin2, red);
  analogWrite(greenpin2, green);
  analogWrite(bluepin2, blue);
  analogWrite(redpin3, red);
  analogWrite(greenpin3, green);
  analogWrite(bluepin3, blue);
}
