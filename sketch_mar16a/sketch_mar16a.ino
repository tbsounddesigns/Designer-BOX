#include <MIDI.h>
#include <Bounce2.h>
// Both of these libraries are necessary for this to function properly.
const int channel = 16; // sending all MIDI in this code on last channel. Keeps it away from other devices, most of the time.
const int maxValue = 127; // can be used both for Control Change and MIDI note ON OFF
const int minValue = 0; // can be used both for Control Change and MIDI note
const int ledPin = 13; // internal LED (Teensy LC)
Bounce button1 = Bounce(1, 5);
Bounce button2 = Bounce(2, 5);
Bounce button3 = Bounce(3, 5);
Bounce button4 = Bounce(4, 5);
Bounce button5 = Bounce(5, 5);
Bounce button6 = Bounce(6, 5);
Bounce button7 = Bounce(7, 5);
Bounce button8 = Bounce(8, 10);
// 5 = 5 ms debounce time, which is appropriate for good quality mechanical pushbuttons (***CHANGE IF NECESSARY***)


// MIDI_CREATE_DEFAULT_INSTANCE();

void setup() // set up pins based on what type of signal is going in. In this case, the pins are reading the buttons switching on and off
{
pinMode(1, INPUT_PULLUP);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(ledPin, OUTPUT); // internal LED for Teensy LC


// MIDI.begin(16);
}
void loop() {

// setup for the micro-controller to continue reading the status of the button:
button1.update();
button2.update();
button3.update();
button4.update();
button5.update();
button6.update();
button7.update();
button8.update();

// when specified button is PRESSED:
if (button1.fallingEdge()) {
MIDI.sendControlChange(1, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
if (button2.fallingEdge()) {
MIDI.sendControlChange(2, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
if (button3.fallingEdge()) {
MIDI.sendControlChange(3, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
if (button4.fallingEdge()) {
MIDI.sendControlChange(4, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
if (button5.fallingEdge()) {
MIDI.sendControlChange(5, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
if (button6.fallingEdge()) {
MIDI.sendControlChange(6, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
if (button7.fallingEdge()) {
MIDI.sendControlChange(7, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
if (button8.fallingEdge()) {
MIDI.sendControlChange(8, maxValue, channel);
digitalWrite(ledPin, HIGH);
}
// when specified button is RELEASED:
if (button1.risingEdge()) {
MIDI.sendControlChange(1, minValue, channel);
digitalWrite(ledPin, LOW);
}
if (button2.risingEdge()) {
MIDI.sendControlChange(2, minValue, channel);
digitalWrite(ledPin, LOW);
}
if (button3.risingEdge()) {
MIDI.sendControlChange(3, minValue, channel);
digitalWrite(ledPin, LOW);
}
if (button4.risingEdge()) {
MIDI.sendControlChange(4, minValue, channel);
digitalWrite(ledPin, LOW);
}
if (button5.risingEdge()) {
MIDI.sendControlChange(5, minValue, channel);
digitalWrite(ledPin, LOW);
}
if (button6.risingEdge()) {
MIDI.sendControlChange(6, minValue, channel);
digitalWrite(ledPin, LOW);
}
if (button7.risingEdge()) {
MIDI.sendControlChange(7, minValue, channel);
digitalWrite(ledPin, LOW);
}
if (button8.risingEdge()) {
MIDI.sendControlChange(8, minValue, channel);
digitalWrite(ledPin, LOW);
}
while (MIDI.read()){ // necessary to prevent crashing, in case the micro- controller receives MIDI it was not prepared to decode
}
}
