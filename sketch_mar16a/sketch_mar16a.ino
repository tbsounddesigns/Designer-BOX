#include <MIDIUSB.h>
#include <Bounce2.h>
// Both of these libraries are necessary for this to function properly.
const int channel = 16;    // sending all MIDI in this code on last channel. Keeps it away from other devices, most of the time.
const int maxValue = 127;  // can be used both for Control Change and MIDI note ON OFF
const int minValue = 0;    // can be used both for Control Change and MIDI note
const int ledPin = 13;     // internal LED (Teensy LC) -- might need to change this to "LED_BUILTIN" if using another board

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

void setup()  // set up pins based on what type of signal is going in. In this case, the pins are reading the buttons switching on and off
{
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);  // internal LED for Teensy LC


  // begin(16);
}

// every time the function is called, it will use this as a template, and replace the variables with what you specify in the "void loop" section
void sendControlChange(byte control, byte value, byte channel) {
  midiEventPacket_t event = { 0x0B, 0xB0 | (channel - 1), control, value };
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
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
    sendControlChange(1, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (button2.fallingEdge()) {
    sendControlChange(2, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (button3.fallingEdge()) {
    sendControlChange(3, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (button4.fallingEdge()) {
    sendControlChange(4, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (button5.fallingEdge()) {
    sendControlChange(5, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (button6.fallingEdge()) {
    sendControlChange(6, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (button7.fallingEdge()) {
    sendControlChange(7, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (button8.fallingEdge()) {
    sendControlChange(8, maxValue, channel);
    digitalWrite(ledPin, HIGH);
  }
  // when specified button is RELEASED:
  if (button1.risingEdge()) {
    sendControlChange(1, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
  if (button2.risingEdge()) {
    sendControlChange(2, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
  if (button3.risingEdge()) {
    sendControlChange(3, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
  if (button4.risingEdge()) {
    sendControlChange(4, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
  if (button5.risingEdge()) {
    sendControlChange(5, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
  if (button6.risingEdge()) {
    sendControlChange(6, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
  if (button7.risingEdge()) {
    sendControlChange(7, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
  if (button8.risingEdge()) {
    sendControlChange(8, minValue, channel);
    digitalWrite(ledPin, LOW);
  }
}
