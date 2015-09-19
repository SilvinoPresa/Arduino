#include <LiquidCrystal.h> //Load LCD library
LiquidCrystal LCD(10,9,5,4,3,2); //LCD objet
int myCounter=0; //declare variable myCounter

void setup() {
  // put your setup code here, to run once:
  LCD.begin(16,2); //size of the object -first column and then rows-
  LCD.setCursor(0,0); //set the cursor at upper left display
  LCD.print("My Timer: "); //print of the first line
}

void loop() {
  // put your main code here, to run repeatedly:
  for (myCounter=1; myCounter<=10; myCounter=myCounter+1){
    LCD.setCursor(0,1); //set cursor on the second line
    LCD.print("           "); //display an empty line
    LCD.setCursor(0,1); //set cursor on the second line
    LCD.print(myCounter); //print current value
    LCD.print(" seconds"); //finish the print on the second line
    delay(1000); //delay 1000 miliseconds
  }
  for (myCounter=10; myCounter>=0; myCounter=myCounter-1){
    LCD.setCursor(0,1); //set cursor on the second line
    LCD.print("           "); //display an empty line
    LCD.setCursor(0,1); //set cursor on the second line
    LCD.print(myCounter); //print current value
    LCD.print(" seconds"); //finish the print on the second line
    delay(1000); //delay 1000 miliseconds
  }
}
