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
- Wooden (Add measurements)
- Screws (Add sizes)
- Four plastic water bottles
- Wire
- Sheet Metal
- Hot glue
- Tape
- Cardboard
- Black Paint
- Plexiglass

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
 Four gears were 3D printed
 (Add picture and measurements)
 
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

### Parts of Build
    Ramp, funnels, gears, frame, etc. 
    Put engineering drawings here
      
### Overall Assembly
   
## Desgin Decision Discussion
    Could someone buld on top of your desgin with modifications?
    Design decisions are described completely
    
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
    
    
  
