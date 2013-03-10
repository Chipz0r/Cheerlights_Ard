
//---bof---RGBL-Analog Preamble
//RGB LED pins
int ledAnalogOne[] = {3, 5, 6}; 
//the three pins of the first analog LED 3 = redPin, 5 = greenPin, 6 = bluePin                                
//These pins must be PWM

//Defined Colors (different RGB (red, green, blue) values for colors
const byte RED[] = {0, 255, 255}; 
const byte ORANGE[] = {172, 251, 255}; 
const byte YELLOW[] = {0, 200, 255}; 
const byte GREEN[] = {255, 0, 255}; 
const byte BLUE[] = {255, 255, 0}; 
const byte INDIGO[] = {200, 255, 220}; //? 
const byte VIOLET[] = {232, 255, 233}; //?
const byte CYAN[] = {255, 0, 0}; 
const byte MAGENTA[] = {0, 255, 200}; 
const byte WHITE[] = {0, 50, 150}; 
const byte WARMWHITE[] = {0, 70, 220};
const byte BLACK[] = {255, 255, 255}; //?
const byte PURPLE[] = {100, 255, 160}; 
//---eof---RGBL-Analog Preamble

// Variable Setup
long lastConnectionTime = 0; 
String lastCommandString = "";
byte lastCommand[] = {255, 255, 255};

void setup() 
{
  //delay(100);
  for(int i = 0; i < 3; i++) {   
    pinMode(ledAnalogOne[i], OUTPUT);   //Set the three LED pins as outputs   
    
  // Setup Serial
  Serial.begin(9600);
  delay(100);
  
  Serial.flush();
  delay(100);
  }
}  

void loop() {
  
   // Listen to serial commands from RaspPi
  if(Serial.available() > 0)
  {  
    delay(100); 

    char charIn = 0; 
    byte i = 0; 
    char stringIn[32] = "";
   
    while(Serial.available())
    {
      charIn = Serial.read();
      stringIn[i] = charIn; 
      i += 1;
    }
    
    // Echo Received Commands on the Serial Monitor
    Serial.println("CheerLight Command Received: "+String(stringIn));
    delay(200);
   
    // Light the tree
    if (String(stringIn) == "red")
    //if (response.indexOf("white") > 0)
    {  
       fadeToColor(ledAnalogOne, lastCommand, WHITE, 10);
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = WHITE[i];
       }
       lastCommandString = "white";  
    }
    else if (String(stringIn) == "black")
    //else if (response.indexOf("black") > 0)
    {  
       fadeToColor(ledAnalogOne, lastCommand, BLACK, 10);  
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = BLACK[i];
       }  
       lastCommandString = "black";  
    }
    else if (String(stringIn) == "red")
    {  
       fadeToColor(ledAnalogOne, lastCommand, RED, 10);  
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = RED[i];
       }  
       lastCommandString = "red";  
    }
    else if (String(stringIn) == "green")
    {  
       fadeToColor(ledAnalogOne, lastCommand, GREEN, 10);  
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = GREEN[i];
       }  
       lastCommandString = "green";  
    }
    else if (String(stringIn) == "blue")
    {  
       fadeToColor(ledAnalogOne, lastCommand, BLUE, 10);  
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = BLUE[i];
       }  
       lastCommandString = "blue";  
    }
    else if (String(stringIn) == "cyan")
    {  
       fadeToColor(ledAnalogOne, lastCommand, CYAN, 10); 
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = CYAN[i];
       }  
       lastCommandString = "cyan";  
    }
    else if (String(stringIn) == "magenta")
    {  
       fadeToColor(ledAnalogOne, lastCommand, MAGENTA, 10);  
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = MAGENTA[i];
       }  
       lastCommandString = "magenta";  
    }
    else if (String(stringIn) == "yellow")
    {  
       fadeToColor(ledAnalogOne, lastCommand, YELLOW, 10);  
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = YELLOW[i];
       }  
       lastCommandString = "yellow";  
    }
    else if (String(stringIn) == "purple")
    {  
       fadeToColor(ledAnalogOne, lastCommand, PURPLE, 10);  
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = PURPLE[i];
       }  
       lastCommandString = "purple";  
    }
    else if (String(stringIn) == "orange")
    {  
       fadeToColor(ledAnalogOne, lastCommand, ORANGE, 10); 
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = ORANGE[i];
       }  
       lastCommandString = "orange";  
    }
    else if (String(stringIn) == "warmwhite")
    {  
       fadeToColor(ledAnalogOne, lastCommand, WARMWHITE, 10);
       delay(3000);
       for(int i = 0; i < 3; i++) {   
          lastCommand[i] = WARMWHITE[i];
       }  
       lastCommandString = "warmwhite";  
    }
    else if (String(stringIn) == "black")
    {  
      fadeToColor(ledAnalogOne, lastCommand, BLACK, 10);
      delay(3000);
      for(int i = 0; i < 3; i++) {   
          lastCommand[i] = BLACK[i];
      }  
      lastCommandString = "black";  
    }
    else
    {
      Serial.println("No match.");
      //lastCommand = "(no match)";  
    }
    
    // Echo command
    delay(200);
    Serial.println("CheerLight Command Received: "+lastCommandString);
    Serial.println();
    delay(200); 
    
  }
}

/* Sets the color of the LED to any RGB Value   led - (int array of three values defining the LEDs pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin))   color - (byte array of three values defing an RGB color to display (color[0] = new Red value, color[1] = new Green value, color[2] = new Red value*/
void setColor(int* led, byte* color){ 
  for(int i = 0; i < 3; i++){             //iterate through each of the three pins (red green blue)   
    analogWrite(led[i], 255 - color[i]);  //set the analog output value of each pin to the input value (ie led[0] (red pin) to 255- color[0] (red input color)                                         
    //we use 255 - the value because our RGB LED is common anode, this means a color is full on when we output analogWrite(pin, 0)                                         
    //and off when we output analogWrite(pin, 255).  
  }
}

/* A version of setColor that takes a predefined color (neccesary to allow const int pre-defined colors */
void setColor(int* led, const byte* color) { 
  byte tempByte[] = {color[0], color[1], color[2]}; 
  setColor(led, tempByte);
}

/* Fades the LED from a start color to an end color at fadeSpeed   
led - (int array of three values defining the LEDs pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin))   
startCcolor - (byte array of three values defing the start RGB color (startColor[0] = start Red value, startColor[1] = start Green value, startColor[2] = start Red value   
endCcolor - (byte array of three values defing the finished RGB color (endColor[0] = end Red value, endColor[1] = end Green value, endColor[2] = end Red value   
fadeSpeed - this is the delay in milliseconds between steps, defines the speed of the fade*/ 
void fadeToNumColor(int* led, byte* startColor, byte* endColor, int fadeSpeed) {  
  int changeRed = endColor[0] - startColor[0];                             //the difference in the two colors for the red channel  
  int changeGreen = endColor[1] - startColor[1];                           //the difference in the two colors for the green channel   
  int changeBlue = endColor[2] - startColor[2];                            //the difference in the two colors for the blue channel  
  int steps = max(abs(changeRed),max(abs(changeGreen), abs(changeBlue)));  //make the number of change steps the maximum channel change    
  for(int i = 0 ; i < steps; i++) {                                        //iterate for the channel with the maximum change   
    byte newRed = startColor[0] + (i * changeRed / steps);                 //the newRed intensity dependant on the start intensity and the change determined above   
    byte newGreen = startColor[1] + (i * changeGreen / steps);             //the newGreen intensity   
    byte newBlue = startColor[2] + (i * changeBlue / steps);               //the newBlue intensity   
    byte newColor[] = {newRed, newGreen, newBlue};                         //Define an RGB color array for the new color   
    setColor(led, newColor);                                               //Set the LED to the calculated value   
    delay(fadeSpeed);                                                      //Delay fadeSpeed milliseconds before going on to the next color  
  }  
  setColor(led, endColor);                                                 //The LED should be at the endColor but set to endColor to avoid rounding errors
}

/* A version of fadeToColor that takes predefined colors (neccesary to allow const int pre-defined colors */
void fadeToColor(int* led, const byte* startColor, const byte* endColor, int fadeSpeed) {  
  byte tempByte1[] = {startColor[0], startColor[1], startColor[2]};   
  byte tempByte2[] = {endColor[0], endColor[1], endColor[2]};   
  fadeToNumColor(led, tempByte1, tempByte2, fadeSpeed);
}


