/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/
 
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
int redPin = 7;
int greenPin = 6;
int bluePin = 3;
int r;//100
int b;//10
int g;//1
int r2;
int b2;
int g2;


#define REDPIN 7
#define GREENPIN 6
#define BLUEPIN 3


 
void setup() 
{
   Serial.begin(9600);
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
  
}
 
 
void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
 //  double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
 
   Serial.println(peakToPeak);

   r =(int) peakToPeak/10;
   b = (int)(peakToPeak - (r*1000))/10;
   g = peakToPeak - (r*1000)-(b*10);

  //Serial.println(r);
  // Serial.println(b);
  // Serial.println(g);

   delay(1000);
  
//  r2 = (int) (r/10) * 255;
//  b2 = (int) (b/10) * 255;
//  g2 = (int) (g/10) * 255;

 r2 = r;
  b2 = b;
  g2 = g;

   setColor(r2,g2,b2);
delay(100);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
 // analogWrite(redPin, red);
  //analogWrite(greenPin, green);
 // analogWrite(bluePin, blue);  
}



