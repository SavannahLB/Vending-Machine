# BAE 305 Project - Vending-Machine
Group Members: Savannah Beyerle, Johnna Campbell, Marlenne Conrado, Brendan Henegar, Hayley Lawman

## Summary

For the BAE 305 project, a miniature vending machine was created. This system works like most vending machines: a button will select a product leading to a dispensing system giving said product to the user. In this case, the dispensing system is a conglomerate of funnels and gears that use gravity to pull the wanted item down to the user. These products for the user are four different types of candies (Skittles, M&Ms, Reeses Pieces, and Peanut M&Ms). A specilized button (four in total) activates one of four gears, allowing candy to flow from the attached funnel system. Overall, each candy is placed in its funnel. When the specific candy's button is pushed, an attached LCD screen will display the candy selected while the gear attached to a DC toy motor and positioned under the funnel will spin half a rotation. This will give the user a handful of that candy while reblocking that funnel, stopping more candy from falling. A ramp positioned below all four gear systems will lead the candy to one location so the user can collect the candy in their hand. When assembled, the machine was tested multiple times to get the correct spin of the gear and candy ratio for the user. After assembly, the miniature vending machine functions as intended, as listed in the project backlog.

## Design Description
    
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
- Acrylic Sheet (9 x 22.5 X 0.125 in)
- Candy
  - M&Ms
  - Skittles
  - Reese's Pieces
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
Four unique gears are 3D modeled and printed for the funneling/dispensing system. These gears are attached to DC motors and situated underneath the funnels. When the button is pushed, the DC motor will spin the gear, emptying a portion of candy to the user. Below is an image of the 3D model of the gear. The gear follows a cylinder design with a 10 cm radius and a height of 8 cm. The circular top is split into four sections, with the two opposite sides removed to give the gear its teeth. A small hole is made at the bottom of the gear to place the DC motor into. The center of the gear is hollowed out so that the print can minimize the print time while lower int he the weight of the gear for the DC motor to spin. 

<img src="3D Gear Print Model.png">
 
### Schematics
To house the entire circuit, two Red Boards are used. The vending machine's circuit is split into three sections: the buttons, the LCD screen, and the motors. Board one contains the buttons and LCD screen, while board two holds the four DC motors. Both individual circuits are viewable below.
#### Circuit 1
<img src="Schematics/Circuit 1 (Buttons and LCD).png">

#### Circuit 2
<img src="Schematics/Circuit 2 Schematic (Motors 1 and 2).png">
 
The two Red Boards are connected by wiring three specific pins on each board to the other board's pins. One connection is of the ground pins on both boards. The other two connections involve connecting one board's TX D1 pin to the other board's RX D0 pin and vice versa. The overall schematic is seen below. 
#### Overall Schematic
<img src="Schematics/Complete Circuit Schematic.png">

### Code

The goal for the Arduino IDE code was for the user to press a button in order to make one of the gears spin to dispense candy as an LCD displays the kind of candy that corresponds to that gear. Two Arduino IDE code files were used. One for the "input" Arduino Board with all the buttons and the LCD screen, and one for the "output" Arduino board with the motors. Two Arduinos were needed because there weren't enough digital pins in only one arduino for the LCD screen and the 4 motors. 

The code for the input board starts by initializing the needed variables and setting up the buttons as inputs. It is important to note that even though the LCD is in the input board code, it truly is an output. It was added into this code file regardless because it was convenient to make it respond because a button was pressed instead of making it respond when a motor spun. 
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

```

Then, an if-else loop scans for user input from the buttons. When one of the buttons is pressed, a number from 1 to 4 (Assigned to each motor at variable initialization) is sent over to the output board code. To achieve that, the function Serial.print() was used. 

```
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

The output board code also starts by initializing the needed variables and setting up the motors as outputs. 

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

```

Then a string called motor was initialized to be 0. Later that variable was set to Serial.readString (). That function reads the information sent over from the input board. 

```

void loop() {

  String motor = "0" ;


  while (Serial.available() == 0) {}
  motor = Serial.readString();       //receives information sent over from the input board code
  Serial.println("Motor value is");
  Serial.println(motor);
  
```

Then, that received information in used in an else-if statement. Depending on what input is received, a different motor turns. The function spinVariable() sets the speed of the motor corresponding to said variable and delay() sets the amount of time the motor will spin for. 

```
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

```

Then, more motor setup entails.

```
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

It is important to note that when uploading each code to its respective Arduino, the Arduinos must be disconnected from each other.

### Parts of Build
    
#### Wooden Frame
The wooden frame holds the weight of the vending machine while holding all the other parts in place. A drawing of the frame can be viewed below. The two base slabs are 3.5 x 10.5 x 0.5 inches. The wooden legs atop the slabs are 16 x 3.5 x 0.5 inches. The frame has two smaller wooden beams to connect the legs, located at the top and middle of the machine. Each beam has a size of 24 x 1 x 1 inches. The top beam also connects and holds the funnels to the structure, while the middle beam has the four DC motors for the gears connected to it. Under the middle beam is a back panel to keep the candy from falling out of the back of the machine. The panel is 22.5 inches long and 4 inches tall.

<img src="Engineering Drawing/Frame Drawing.png">

#### Funnels
Four water bottles are cut at the bottom so that the bottle models a funnel-like design, as seen in the image below. The top diameter of the bottle is 2.75 inches, while the lower diameter is 1.5 inches. Each bottle is cut to a height of 7 inches. These funnels are to hold the candy. 

<img src="Engineering Drawing/Funnel Drawing.png">

#### Gears
In addition to the 3D print, each gear will have four cardboard cutouts placed within it, two in each open section. The cardboard wedge minimize the room for the gear to house candy dispended from the funnel. This helps with controlling the flow and bottlenecking of candy in the machine. Each wedge matches the gear's circumference to fit nicely inside the opening with an overhang. 

<img src="Engineering Drawing/Gear Drawing.png">

#### Ramp
A piece of sheet metal is formed to model a ramp-like design. The ramp looks like a trapezoid atop a rectangle, as seen in the drawing below. The rectangle is 22.5 inches long with a width of 3.5 inches. The outer rim of the rectangle has a 1-inch high vertical piece to attach it to the wooden legs while also acting as a wall to keep the fallen candy in. The trapezoidal shape continues with a base of 22.5 inches to match the rectangle. The second base has a size of 4 inches, while the length extends to 9 inches. The sides of the trapezoid also have a wall to keep the dispended candy in, standing at 1.25 inches tall. The smaller base is left open without a wall, as this will be where the user accesses the candy. 

<img src="Engineering Drawing/Ramp Drawing.png">

### Overall Assembly
All four parts are combined to create the vending machine drawn below. 
<img src="Engineering Drawing/Overall Build Drawing.png">

Eight small holes are drilled into the upper wooden beam of the wooden structure so that four steel wires may pass through. Each wire is placed in two holes and wrapped around one of the bottle funnels, with the smaller diameter facing down. Four DC motors with 3D-printed gears attached are placed directly below the funnels. To hold the gears in place, each motor is tied with the steel wire to the middle wooden beam. Right below the frame's back panel is the ramp. The ramp is slightly tilted, with the trapezoidal side lower than the rectangular side. A sheet of acrylic (9 x 22.5 X 0.125 inches) is fit between the two legs of the machine, below the upper wooden beam. The acrylic stops any candy from falling toward the user before the ramp and allows the user to see the movement of the gears. The candy will start in the funnels, with each funnel housing a different type of candy. When the gear spins, the candy will fall into the gear and then into the ramp tray. When the gear stops spinning, the funnel's hole is blocked, stopping the candy. The candy already dispensed in the tray will move towards the smaller opening in the ramp for the user to access. The physical vending machine can be viewed below.

<img src="Pictures/Vending Machine (Front).jpg">
<img src="Pictures/Vending Machine (Back).jpg">

## Design Decision Discussion
During the design decision process, several different gear designs, circuit configurations, and wooden frame arrangements were tested to ensure the most practical and efficient resulting operation of the vending machine. The gear design went from having a solid interior with 5 teeth and 5 openings, to a hollow interior with two bigger teeth and openings, in order to speed up printing times, reduce cost, and streamline the design. Two cardboard cutouts were then added to each opening of the gears to keep the candy contained and prevent any pieces of candy from falling through the open back of the frame. The circuits were originally designed to have the four buttons and LCD on the same board, but they were then adjusted to have the buttons on their own board in order to make pushing them more accessible for the user. The wooden frame was designed to support the weight of the gears and funnels, and stand upright while acting as the support system for the vending machine. The ramp was then added to transport the candy from the gears into the user's hands. The final design is successful in operation, but could be modified if needed, as the circuit components are able to be easily adjusted and switched around, and the gears and funnels are detachable from the base. The construction of the wooden frame may be harder to change, since the wooden pieces are nailed together, but it would still be possible to build on top of it if needed.
    
### Wooden Frame
The wood frame is made of 4x1 southern pine lumber. 
### Funnels
The funnels are recycled from a wide mouth flavored water.
### Gears
The gears were designed using a CAD software, then 3D printed. The gear design was oversided, thus we had to at cardboard inserts to reduce the gears' total capacity. 
### Ramp
The ramp is made from bent sheet metal. The design uses three pieces of metal that are pop riveted together.

## Testing Description
To determine if each function of the vending machine works, the team first picked a specific candy type from the signage that correlated with a button color displayed on the signage below the candy type signage. A team member located that specific button (1 of 4; green, yellow, red, and, blue) from the Sparkfun Inventor's Kit and ensured there was a container at the bottom of the hopper to cacth the candy that falls from the specified funnel. Then the following procedure is followed for each candy type (M&Ms, Reese's Pieces, Skittles, and Peanut M&Ms) and each colored button. 
1. Ensure all gears are in a position that blocks the outlet of the candy, and that each bottle candy storage has candy inside it.
2. Select 1 of four candy types and locate button of corresponding color.
3. Ensure something is below hopper to catch candy once dispensed.
4. Press selected button.
5. Ensure the correct gear dispenses desired candy.
6. Ensure the name of the candy appears on the LCD after pressing the button.
7. Replace dispensed candy into bottle candy holders.
8. Repeat for the other 3 candies/buttons. 
    
    
    
## Testing Results
The teams observed that pressing each color button on the Sparkfun Inventors Kit RedBoard resulted in the following functions successfully:
1. The correct candy was dispensed when the specific color button was pressed.
2. The correct candy name was displayed on the LCD as a result of pressing the corresponding button. 
    
## Test Result Discussion
The results of the tests ran to confirm the capabilities of the vending machine are as follows:
1. The code was properly written, formatted, and uploaded, and the desired functions of the motors, buttons and LCD screen were perfoemd based on what the code was. 
2. The motors turned enough and at an acceptable enough speed to allow candy to fall from the bottles, as well as to catch the candy and drop the candy into the        hopper.
3. The specified buttons being in the LOW position (or pressed) does initate the correct motor to spin at a specified speed for a specified amount of time.
4. The specified buttons being pressed resulted in the LCD to print the specified candy names based on the input of the code. 
5. The candy types chosen to be implemented into the design worked well with the functional limitations for the design, i.e. being gravity fed and the candy falling if the outlet of the candy storage is not blocked properly.  

  The vending machine was able to dispense 4 different candies, M&Ms, Skittles, Reese's Pieces, and Peanut M&Ms, using 4 different color buttons, and display the name of the specific candy on the LCD screen after the button is pressed. The candy was able to be stored and then dispensed when requested by the button being pressed.  
    This design would work anywhere there is a large enough surface to set it on and a power source to plug in the RedBoards that hold the LCD screen, buttons, and power the gears. The design would be desired anywhere people tend to want a small snack. 
      The design works well, the buttons being pressed consistently result in the listed functions, and the device does not operate unprovoked or without a button being pressed. The buttons and candies correlate correctly, as in, the candy expected to be dispensed when the specific button is pressed is what is dispensed, and there is no room in the code for circuits to cause disfunction in that way. The LCD always shows the correct candy selected on the screen after he button is pressed.
    The main limitations are the size restraints based on our specific materials. The motors can only be so much distance apart because the wires we have available to connect the two breadboards and the motors to the same Redboard are relatively short. Another limitation is that only one candy can be dispensed at once and still have all the functions work correctly. Pressing 2 buttons at once is not accounted for in the code. The candy types being used in the device are also limited becuase bigger candies would most likely jam the gears and not dispense well, and too small of candies would not be able to be blocked by the storage outlet and gear well enough to stop the flow of candy when it is not supposed to dispense. Lastly, if the candy gets switched out, the user would have to change the code to display the correct candy names on the LCD. 
    
   
    
    
  
