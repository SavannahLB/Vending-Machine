
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

