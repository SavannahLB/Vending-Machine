// this is for the arduino with all the buttons and lcd display

#include <LiquidCrystal.h>            //the liquid crystal library contains commands for printing to the display
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);     // tell the RedBoard what pins are connected to the display

// initializes variables:
int yellowButtonPin = 4;
int redButtonPin = 5;
int blueButtonPin = 6;
int greenButtonPin = 7;

int yellowMotorSpeed = 0;
int redMotorSpeed = 0;
int blueMotorSpeed = 0;
int greenMotorSpeed = 0;

int yellowMotor = 1;
int redMotor = 2;
int blueMotor = 3;
int greenMotor = 4;

void setup() {

  //inputs

  lcd.begin(16, 2);                         //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                              //clear the display

  //set the button pins as inputs
  pinMode(yellowButtonPin, INPUT_PULLUP);
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);




  Serial.begin(9600);           //begin serial communication with the computer

}

void loop() {

  if (digitalRead(yellowButtonPin) == LOW) { //if the yellow button is pressed, send yellowMotor over to the input Board

    //talks to the "output" board
    Serial.print(yellowMotor);
    delay (500);

    lcd.clear();                              //clear the LCD

    lcd.setCursor(0, 0);                      //set the cursor to the top left position

    lcd.print("M&Ms");                        //Print M&Ms
    
    delay (2500);                             //Display the word for 2.5 seconds

    lcd.clear();  


  }
  else if (digitalRead(redButtonPin) == LOW) { // if the red button is pressed, send redMotor over to the input Board

    Serial.print(redMotor);

    delay (500);

    lcd.clear();                              //clear the LCD

    lcd.setCursor(0, 0);                      //set the cursor to the top left position

    lcd.print("Skittles");

    delay (2500);

    lcd.clear();  
    
  }
  else if (digitalRead(blueButtonPin) == LOW) { // if the blue button is pressed, send blueMotor over to the input Board

   
    Serial.print(blueMotor);

    delay (500);

    lcd.clear();                              //clear the LCD

    lcd.setCursor(0, 0);                      //set the cursor to the top left position

    lcd.print("Reese's Pieces");

    delay (2500);

    lcd.clear();  

  }
  else if (digitalRead(greenButtonPin) == LOW) { // if the green button is pressed, send greenMotor over to the input Board

    Serial.print(greenMotor);

    delay (500);

    lcd.clear();                              //clear the LCD

    lcd.setCursor(0, 0);                      //set the cursor to the top left position

    lcd.print("Peanut M&Ms");

    delay (2500);

    lcd.clear();  

  }
  else {

    yellowMotorSpeed = 0;
    redMotorSpeed = 0;
    blueMotorSpeed = 0;
    greenMotorSpeed = 0;

  }  
 
  

}


