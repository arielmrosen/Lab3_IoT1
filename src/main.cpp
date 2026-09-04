#include <Arduino.h>

uint8_t value;

void setup() {
  DDRD &= 0x00; // Set PD4-PD7 as input
  PORTD |= 0xF0; // Enable pull-up resistors for PD4-PD7
  DDRB &= 0x0F; // Set PB4-PB7 as output
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate

}

void loop() {
  value = PIND; //Read switches
  value = value & 0xF0;// Mask the values (0xF0)
  value >>= 4;// Shift right value >> 4
  value = ~value; // Invert the value
  value = value & 0x0F; // Mask the value (0x0F)
  value = ~value; // Invert the value again
  value = value +1; // Increment the value by 1
  value = value & 0x0F; // Mask the value (0x0F)
  PORTB = value; // Display on LEDs
  Serial.println("---------------"); // Print a separator line
  Serial.print("Binary:"); // Print the label for binary output
  Serial.println(value, BIN); // Print the value in binary format
  Serial.print("Decimal:"); // Print the label for decimal output
  Serial.println(value); // Print the value in decimal format
  delay(1000); // Delay for 1000 milliseconds
}
