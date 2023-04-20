# BAE 305 Project - Vending-Machine
Group Members: Savannah Beyerle, Johnna Campbell, Marlenne Conrado, Brendan Henegar, Hayley Lawman

  ## Summary
    Write Summary of Project Here 
    Describe the project and the reuslts
    DONE
For the BAE 305 project, a miniature vending machine was created. This system works like most vending machines: a button will select a product leading to a dispensing system giving said product to the user. In this case, the dispensing system is a conglomerate of funnels and gears that use gravity to pull the wanted item down to the user. These products for the user are four different types of candies (Skittles, M&Ms, Reeses Pieces, and 4th). A specilized button (four in total) activates one of four gears, allowing candy to flow from the attached funnel system. Overall, each candy is placed in its funnel. When the specific candy's button is pushed, an attached LCD screen will display the candy selected while the gear attached to a DC toy motor and positioned under the funnel will spin half a rotation. This will give the user a handful of that candy while reblocking that funnel, stopping more candy from falling. A ramp positioned below all four gear systems will lead the candy to one location so the user can collect the candy in their hand. When assembled, the machine was tested multiple times to get the correct spin of the gear and candy ratio for the user. After assembly, the miniature vending machine functions as intended, as listed in the project backlog.

## Design Description
    Could a technician build your design based on this documentation?
    
### Supplies Needed
- Two Sparkfun Electronics RedBoard DEV-13975
- Sparkfun Electronics Kit Parts:
  - Four toy DC motors
  - Two motor drive boards
  - Wires
  - Breadboard
  - Four buttons
  - LCD screen
  - Potentiometer
- Wood 
  -  2 pieces 16 x 3.5 x 0.5 in
  -  2 pieces 3.5 x 10.5 x 0.5 in
  -  2 pieces 24 x 1 x 1 in
- Screws (2 inch)
- Pull Rivets
- Four plastic water bottles
- Wire
- Sheet Metal
- Hot glue
- Tape
- Cardboard
- Black Paint
- Plexiglass (9 x 22.5 X 0.125 in)
- Candy
  - M&Ms
  - Skittles
  - Reese's Puffs
  - Peanut M&Ms

### Tools Used
- Pilers
- Drill
- Hot glue gun
- 3D Printers
- Ruler/ Measurement Tools
- Pocket Knife
- Scissors
- Laser Cutter

### 3D Printed Parts
    Display and explain 3D Print of Gear
    DONE
Four unique gears are 3D modeled and printed for the funneling/dispensing system. These gears are attached to DC motors and situated underneath the funnels. When the button is pushed, the DC motor will spin the gear, emptying a portion of candy to the user. Below is an image of the 3D model of the gear. The gear follows a cylinder design with a 10 cm radius and a height of 8 cm. The circular top is split into four sections, with the two opposite sides removed to give the gear its teeth. A small hole is made at the bottom of the gear to place the DC motor into. The center of the gear is hollowed out so that the print can minimize the print time while lower int he the weight of the gear for the DC motor to spin. 

<img src="3D Gear Print Model.png">
 
### Schematics
    Display and explain circuit
    DONE
To house the entire circuit, two Red Boards are used. The vending machine's circuit is split into three sections: the buttons, the LCD screen, and the motors. Board one contains the buttons and LCD screen, while board two holds the four DC motors. Both individual circuits are viewable below.
#### Circuit 1
<img src="Schematics/Circuit 1 (Buttons and LCD).png">

#### Circuit 2
<img src="Schematics/Circuit 2 Schematic (Motors 1 and 2).png">
 
 The two Red Boards are connected by wiring three specific pins on each board to the other board's pins. One connection is of the ground pins on both boards. The other two connections involve connecting one board's TX D1 pin to the other board's RX D0 pin and vice versa. The overall schematic is seen below. 
#### Overall Schematic
<img src="Schematics/Complete Circuit Schematic.png">

### Code

Two Arduino IDE code files were used. One for the "input" Arduino Board with all the buttons and the LCD screen, and one for the "output" Arduino board with the motors. Two Arduinos were needed because there weren't enough digital pins in only one arduino for the LCD screen and the 4 motors. 

The input board code: 

```

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

```

The output board code: 

```

// initializing variables


const int AIN1 = 13;           //control pin 1 on the motor driver for the yellow button motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the yellow button motor
const int PWMA = 11;            //speed control pin on the motor driver for the yellow button motor

//the red button motor will be controlled by the motor B pins on the motor driver
const int PWMB = 10;           //speed control pin on the motor driver for the red button motor
const int BIN2 = 9;           //control pin 2 on the motor driver for the red button motor
const int BIN1 = 8;           //control pin 1 on the motor driver for the red button motor

//the blue button motor will be controlled by the motor A pins on the motor driver
const int xAIN1 = 7;           //control pin 1 on the motor driver for the blue button motor
const int xAIN2 = 4;            //control pin 2 on the motor driver for the blue button motor
const int xPWMA = 6;            //speed control pin on the motor driver for the blue button motor

//the green button motor will be controlled by the motor B pins on the motor driver
const int xPWMB = 5;           //speed control pin on the motor driver for the green button motor
const int xBIN2 = 3;           //control pin 2 on the motor driver for the left green button motor
const int xBIN1 = 2;           //control pin 1 on the motor driver for the left green button motor

int yellowMotorSpeed = 0 ;     //start speeds at 0
int redMotorSpeed = 0 ;
int blueMotorSpeed = 0;
int greenMotorSpeed = 0;


void setup() {

  //set the motor control pins as outputs

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(xAIN1, OUTPUT);
  pinMode(xAIN2, OUTPUT);
  pinMode(xPWMA, OUTPUT);

  pinMode(xBIN1, OUTPUT);
  pinMode(xBIN2, OUTPUT);
  pinMode(xPWMB, OUTPUT);

  Serial.begin(9600);           //begin serial communication with the computer
}



void loop() {

  String motor = "0" ;


  while (Serial.available() == 0) {}
  motor = Serial.readString();       //receives information sent over from the input board code
  Serial.println("Motor value is");
  Serial.println(motor);
  if (motor == "1") {

                            // Serial.println("motor 1 activated");

    spinYellowMotor(120);    //Sets the speed of the motor
    delay (1000);            //Sets the duration of the spin
    spinYellowMotor(0);      //Tells the motor to stop after the second has passed.

  }
  else if (motor == "2") {
                              //Serial.println("motor 2 activated");
    spinRedMotor(120);          
    delay (1000);
    spinRedMotor(0);
  }
  else if (motor == "3") {

                              //Serial.println("motor 3 activated");
    spinBlueMotor(120);
    delay (1000);
    spinBlueMotor(0);
  }
  else if (motor == "4") {
                              //Serial.println("motor 4 activated");
    spinGreenMotor(120);
    delay (1000);
    spinGreenMotor(0);

  }
  else  {
                              //Serial.println(motor);
    yellowMotorSpeed = 0;
    redMotorSpeed = 0;
    blueMotorSpeed = 0;
    greenMotorSpeed = 0;
  }


}
    


void spinYellowMotor( int yellowMotorSpeed) {                     //function for driving the yellow button motor
  if (yellowMotorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(AIN1, HIGH);                         //set pin 1 to high
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  
  else                                                //if the motor should stop
  {
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMA, abs(yellowMotorSpeed));               
}

void spinRedMotor(int redMotorSpeed)  {                     //function for driving the red button motor
  if (redMotorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(BIN1, HIGH);                         //set pin 1 to high
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  
  else                                                //if the motor should stop
  {
    digitalWrite(BIN1, LOW);                          //set pin 1 to low
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMB, abs(redMotorSpeed));                 
}

void spinBlueMotor(int blueMotorSpeed) {                     //function for driving the blue button motor

  if (blueMotorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(xAIN1, HIGH);                         //set pin 1 to high
    digitalWrite(xAIN2, LOW);                          //set pin 2 to low
  }
  
  else                                                //if the motor should stop
  {
    digitalWrite(xAIN1, LOW);                          //set pin 1 to low
    digitalWrite(xAIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(xPWMA, abs(blueMotorSpeed));                 
}


void spinGreenMotor(int greenMotorSpeed) {                      //function for driving the green button motor

  if (greenMotorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(xBIN1, HIGH);                         //set pin 1 to high
    digitalWrite(xBIN2, LOW);                          //set pin 2 to low
  }
  
  else                                                //if the motor should stop
  {
    digitalWrite(xBIN1, LOW);                          //set pin 1 to low
    digitalWrite(xBIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(xPWMB, abs(greenMotorSpeed));                 
}

```

### Parts of Build
    Ramp, funnels, gears, frame, etc. 
    Put engineering drawings here
    Talk about finalized designs
    
#### Wooden Frame
The wooden frame bares the weight of the build, when holding all the other parts in place. An image of the frame can be viewed below. The frame houses two smaller wooden beams located at the top and middle of the build. The top beam is to connect and hold the funnels to the structure, while the middle beam holds the four DC motors for the gears to connect to.
Back plannel: 22.5 long, 4 inches tall
<img src="Engineering Drawings/Frame Drawing.png">

#### Funnels
Dimensions: top 2 3/4in diameter, 7 inches long, bottom diameter 1.5 in
Four water bottles are cut at the bottom so that the bottle models a funnel like design,, as seen in the image below.
<img src="Engineering Drawings/Funnel Drawing.png">

#### Gears
In addition to the 
<img src="Engineering Drawings/Gear Drawing.png">

#### Ramp
Dimensions: 24 in long, thickness 1 in, widith 1 in
Retangle : 3.5 in X 22.5 in
Trapziod: 22.5 (base 1), 4 in (base 2), length 12.5 in
 boarder thinkness 1.25 in
<img src="Engineering Drawings/Ramp Drawing.png">

### Overall Assembly
<img src="Engineering Drawings/Overall Build Drawing.png">

## Desgin Decision Discussion
    Could someone buld on top of your design with modifications?
    Design decisions are described completely
    Talk about evolution of the build; what changed, what was updated, what is the final result
    
### Wooden Frame
The wood frame is made of 4x1 southern pine lumber. 
### Funnels
The funnels are recycled from a wide mouth flavored water.
### Gears
The gears were designed using a CAD software, then 3D printed. The gear design was oversided, thus we had to at cardboard inserts to reduce the gears' total capacity. 
### Ramp
The ramp is made from bent sheet metal. The disign uses three pieces of metal that are pop riveted together.
## Testing Description
    Could another test engineer replicate your test?
    Test equipment specified 
    Procedures Fully described
    
    
## Testing Results
    Where test results described correctly?
    Were proper tests performed to measure the system capabilites?
    Result are clearly documented
    
## Test Result Discussion
    Are the capabilites of the sytem described?
    Where would this desing work?
    How well does it work?
    What are the limitations? 
    What can it not do?
    
    
  
