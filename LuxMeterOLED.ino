#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <BH1750FVI.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


int inPin1 = 3;
int inPin2 = 4;
int state1 = 0;
int state2 = 0;
int led = 13;
uint16_t Light_Intensity=0;
int SensorValue =0;

BH1750FVI LightSensor;

void setup()   {               
  
  Serial.begin(9600);
  pinMode(inPin1, INPUT_PULLUP);
  pinMode(inPin2, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  LightSensor.begin();
  LightSensor.SetAddress(Device_Address_L); //Address 0x5C
  LightSensor.SetMode(Continuous_H_resolution_Mode);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.display();
  delay(2000);

  }


void loop() {
  
  if (1)
  {
    
    state1 = !digitalRead(3);
    state2 = !digitalRead(4);
    
    if(state1) // display 1
    {    
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(24,20);
        
      Light_Intensity = LightSensor.GetLightIntensity();
      display.print(Light_Intensity);
      display.print(" Lux");
      display.display();
    } 
    else if(state2) //display Temprature
    {    
      
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(24,20);
        
      Light_Intensity = LightSensor.GetLightIntensity();
      display.print(Light_Intensity);
      display.print(" Lux");
      display.display();
     
    }
    else //display Preasure
    {
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(24,20);
        
      Light_Intensity = LightSensor.GetLightIntensity();
      display.print(Light_Intensity);
      display.print(" Lux");
      display.display();    
    }
    
   
   
  }
  else
  {
    display.clearDisplay();
    display.println("Sensor Error");   
    display.display();
   
  }
  
  digitalWrite(led, HIGH);   
  delay(200);
  digitalWrite(led, LOW);    
  
}
