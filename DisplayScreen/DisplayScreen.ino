
//Programers: Vance Clark, Kyle VanLandegent
//Date: 3/1/2022
//Materials, 1 Arduino Uno, 1 Breadboard, 220 ohm Resistor, 13 Wires, Display screen, USB cable
//Credit: MicroBob

#include <LiquidCrystal.h> //Import the LCD library
//Include^
//Init
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); /*Initialize the LCD and
                                        tell it which pins is
                                        to be used for communicating*/

//Global Var
#define contra 9 //Define the pin that controls the contrast of the screen
#define bri 10 //Define the pin the controls the brightness of the screen
//Both pins are PWM so you can analogWrite to them and have them output a variable value


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //Tell the LCD that it is a 16x2 LCD
  pinMode(contra, OUTPUT); //set pin 9 to OUTPUT
  pinMode(bri, OUTPUT); //Set pin 10 to OUTPUT
  //pinMode-ing OUTPUT makes the specified pin output power
  digitalWrite(contra, LOW); /*outputs no power to the contrast pin.
                            this lets you see the words*/
  analogWrite(bri, 255); //Outputs full power to the screen brightness LED
}

void loop() {
  //Put desired message here, to run repeatedly:
  lcd.print(" ELON MUSK "); //Output " GO UKRAINE!!" on the first line of the LCD
  lcd.setCursor(0, 1); 
  
  lcd.print(" FOR PRESIDENT"); //Output " BEAT RUSSIA!!" on the second line of the LCD
  delay(1000); //Wait 1 second
  for (int l = 0; l < 16; l++) { //Repeat 16 times
    lcd.scrollDisplayRight(); //Scroll whole screen to the right one time
    delay(90); //Slight delay for animation (90 milliseconds)
  }
  delay(1000); //Wait 1 second
  for (int l = 0; l < 16; l++)
    lcd.scrollDisplayLeft();
  for (int l = 51; l > -1; l--) { //Repeat 51 times
    analogWrite(bri, l * 5);
    delay(35);
  }
  delay(1000);
  digitalWrite(bri, HIGH);
  for (int l = 0; l < 51; l++) { //Repeat 51 times
    analogWrite(contra, l * 5);
    delay(35);
  }
  delay(1000);
  digitalWrite(contra,LOW);
  lcd.setCursor(0, 0);
}
