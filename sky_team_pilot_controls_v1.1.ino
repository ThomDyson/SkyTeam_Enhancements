const int switch1 = 2;  // Switch 1 (must be ON before Switch 2)
const int switch2 = 3;  // Switch 2 (must be ON before Switch 3)
const int switch3 = 4;  // Switch 3 

const int led1 = 5;  // Default LED (ON when no switch is active)
const int led2 = 6;  // Activated by Switch 1
const int led3 = 7;  // Activated by Switch 2 (only if Switch 1 is ON)
const int led4 = 8;  // Activated by Switch 3 (only if Switch 2 is ON)

const int led5 = 9;  // Status LED for Switch 2 (Blinks if Switch 1 is OFF)
const int led6 = 10; // Status LED for Switch 3 (Blinks if Switch 2 is OFF)

#define SWG1 A0  // Switch 1 connected to A0
#define SWG2 A1  // Switch 2 connected to A1
#define SWG3 A2  // Switch 3 connected to A2

#define LEDB1 11  // LED 1 connected to D11
#define LEDB2 12  // LED 2 connected to D12
#define LEDB3 13  // LED 3 connected to D13
#define LEDB4 A5  // LED 4 connected to A5


void setup() {
    pinMode(switch1, INPUT_PULLUP);
    pinMode(switch2, INPUT_PULLUP);
    pinMode(switch3, INPUT_PULLUP);
    
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
  
  pinMode(SWG1, INPUT_PULLUP);
  pinMode(SWG2, INPUT_PULLUP);
  pinMode(SWG3, INPUT_PULLUP);

  pinMode(LEDB1, OUTPUT);
  pinMode(LEDB2, OUTPUT);
  pinMode(LEDB3, OUTPUT);
  pinMode(LEDB4, OUTPUT);
    // Start with the first LED on
  digitalWrite(LEDB1, HIGH);

}

void loop() {
    bool s1 = !digitalRead(switch1);  // Active LOW
    bool s2 = !digitalRead(switch2);
    bool s3 = !digitalRead(switch3);
  
  //Gear switch positions
   int switchesPressed = (!digitalRead(SWG1)) + (!digitalRead(SWG2)) + (!digitalRead(SWG3));
Serial.print(switchesPressed);
  // Turn off all LEDs first
  digitalWrite(LEDB1, HIGH);
  digitalWrite(LEDB2, HIGH);
  digitalWrite(LEDB3, HIGH);
  digitalWrite(LEDB4, HIGH);

  // Light up the corresponding LED based on the number of switches pressed
  switch (switchesPressed) {
    case 0: digitalWrite(LEDB1, LOW); break;
    case 1: digitalWrite(LEDB2, LOW); break;
    case 2: digitalWrite(LEDB3, LOW); break;
    case 3: digitalWrite(LEDB4, LOW); break;
  }
  
  
    // Main LED logic
    if (s3 && s2 && s1) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
    } else if (s2 && s1) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
    } else if (s1) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
    } else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
    }

    // Handle LED5 (Switch 2 status)
    if (s2) {
        if (s1) {
            digitalWrite(led5, LOW);  // Solid ON if Switch 1 is ON
        } else {
            blinkLED(led5);  // Blink if Switch 1 is OFF
        }
    } else {
        digitalWrite(led5, HIGH);
    }

    // Handle LED6 (Switch 3 status)
    if (s3) {
        if (s2 && s1) {
            digitalWrite(led6, LOW);  // Solid ON if Switch 2 is ON
        } else {
            blinkLED1(led6);  // Blink if Switch 2 is OFF
        }
    } else {
        digitalWrite(led6, HIGH);
    }
}


// Function to blink an LED
void blinkLED1(int ledPin) {
    static unsigned long previousMillis = 0;
    static bool ledState = false;
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 500) {  // Blink every 500ms
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
    }
}

// Function to blink an LED
void blinkLED(int ledPin) {
    static unsigned long previousMillis = 0;
    static bool ledState = false;
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 500) {  // Blink every 500ms
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
    }
}
