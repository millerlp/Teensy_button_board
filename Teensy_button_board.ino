/*	
	Teensy_button_board.ino
	Written for Teensy++ 2.0
	
	Make a Teensy++ 2.0 act as a USB keyboard to send 
	certain combinations of key presses to the computer.
	Meant to simplify data input + scoring of image 
	files by allowing the user to type key combinations
	like "d + return" with a single keystroke. 
	
	This assumes the buttons are wired up with one 
	leg from the Teensy pin, and the other leg wired
	to ground, completing the circuit to ground when
	the button is pressed.
	
	Based on the example for Teensy keyboard:
	http://www.pjrc.com/teensy/td_keyboard.html
	
	Luke Miller April 2015

*/


// Specify which Teensy 2.0 pin each button is attached to.
byte LEDpin = 6;		// D6 has LED attached to it. 
byte prevPin = 18; 	// E6	INT6
byte nextPin = 19; 	// E7	INT7
byte button0Pin = 0; // D0	INT0
byte button1Pin = 1;	// D1	INT1
byte button2Pin = 2;	// D2	INT2
byte button3Pin = 3;	// D3	INT3

const int keydelay = 80; // delay in milliseconds between key commands

void setup() {
// Set the button pins to inputs and
// activate the internal pullup resistors
  pinMode(prevPin, INPUT_PULLUP);
  pinMode(nextPin, INPUT_PULLUP);
  pinMode(button0Pin, INPUT_PULLUP);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  // Set the LED on pin 6 to output mode
  pinMode(LEDpin, OUTPUT);
  // Turn LED off
  digitalWrite(LEDpin, LOW);

  // initialize control over the keyboard:
  Keyboard.begin();

}

void loop() {
		// The main loop simply checks each pin in turn
		// If a pin is low, a character is written
		// to the keyboard
		Keyboard.set_modifier(0);
	
	if (digitalRead(prevPin) == LOW){
		delay(20);
		if (digitalRead(prevPin) == LOW){
			digitalWrite(LEDpin, HIGH);
			Keyboard.println("b");
		}
		// Now idle while waiting for user to release button
		while(digitalRead(prevPin) != HIGH);
		digitalWrite(LEDpin, LOW); // turn off LED
	}
	
	if (digitalRead(nextPin) == LOW){
		delay(20);
		if (digitalRead(nextPin) == LOW){
			digitalWrite(LEDpin, HIGH);
			Keyboard.println("n");
		}
		// Now idle while waiting for user to release button
		while(digitalRead(nextPin) != HIGH);
		digitalWrite(LEDpin, LOW); // turn off LED
	}
	
	if (digitalRead(button0Pin) == LOW){
		delay(20);
		if (digitalRead(button0Pin) == LOW){
			digitalWrite(LEDpin, HIGH);
			Keyboard.println("d");
		}
		// Now idle while waiting for user to release button
		while(digitalRead(button0Pin) != HIGH);
		digitalWrite(LEDpin, LOW); // turn off LED
	}
	
	if (digitalRead(button1Pin) == LOW){
		delay(20);
		if (digitalRead(button1Pin) == LOW){
			digitalWrite(LEDpin, HIGH);
			Keyboard.println("u");
		}
		// Now idle while waiting for user to release button
		while(digitalRead(button1Pin) != HIGH);
		digitalWrite(LEDpin, LOW); // turn off LED
	}
	if (digitalRead(button2Pin) == LOW){
		delay(20);
		if (digitalRead(button2Pin) == LOW){
			digitalWrite(LEDpin, HIGH);
			Keyboard.println("w");
		}
		// Now idle while waiting for user to release button
		while(digitalRead(button2Pin) != HIGH);
		digitalWrite(LEDpin, LOW); // turn off LED
	}
	if (digitalRead(button3Pin) == LOW){
		delay(20);
		if (digitalRead(button3Pin) == LOW){
			digitalWrite(LEDpin, HIGH);
			Keyboard.println("s");
		}
		// Now idle while waiting for user to release button
		while(digitalRead(button3Pin) != HIGH);
		digitalWrite(LEDpin, LOW); // turn off LED
	}	
	
	delay(keydelay);
} // end of main loop
