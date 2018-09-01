#include <MIDI.h>
#include <Servo.h>

MIDI_CREATE_DEFAULT_INSTANCE();

Servo myservo;  // create servo object to control a servo
int servoPin = 8;       // Control pin for servo motor

//const int coil1 =  3;
//const int coil2 =  5;

void setup()
{
    //pinMode(coil1, OUTPUT);
    //pinMode(coil2, OUTPUT);
 
    myservo.attach(servoPin);   
    myservo.write(40);  
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.turnThruOff();
    Serial.begin(115200);
    MIDI.setHandleNoteOn(HandleNoteOn);
    MIDI.setHandleNoteOff(HandleNoteOff);
}
    
void loop()
{
 MIDI.read(); 
}

void HandleNoteOn (byte channel, byte number, byte velocity) { 
  
  if (number == 36) {
  
    myservo.write(60);            // FULL SPEED TO LEFT    
  }   
}

void HandleNoteOff(byte channel, byte number, byte velocity) { 

    if(number==36){
   myservo.write(40);
  }
}
