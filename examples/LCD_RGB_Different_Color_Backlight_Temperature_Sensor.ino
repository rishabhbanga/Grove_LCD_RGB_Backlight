
//Check and display temperature 
#include <Wire.h>
#include "rgb_lcd.h"
const int pinTemp = A0;    
rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 0;
const int b=3975; 
float resistance;
float temperature;
                


void setup()
{
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    delay(1000);
}

void loop()
{
    lcd.clear();
    delay(1000);
    int val = analogRead(pinTemp);                              
    resistance=(float)(1023-val)*10000/val;  
     //calculate the temperature    
    temperature=1/(log(resistance/10000)/b+1/298.15)-273.15;     
    
   
    if (temperature < 25)
    {    
      
      //display temperature
      lcd.print("It's cool at: ");
      lcd.print(temperature);
    }
    
    else
    {
      
      //display temperature
      lcd.print("It's warm at: ");
      lcd.print(temperature);
    }
     
    delay(5000);          
    //display current temperature every reading 5 seconds
}
