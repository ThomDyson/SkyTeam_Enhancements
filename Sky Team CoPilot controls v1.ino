#define flapSwitch1  10  // Switch 1 (must be ON before Switch 2)
#define flapSwitch2  11  // Switch 2 (must be ON before Switch 3)
#define flapSwitch3  12 // Switch 3 
#define flapSwitch4  13  // Switch 4

#define flapLevel8LED  2  // Default LED (ON when no switch is active)
#define flapLevel9LED  3  // Activated by Switch 1
#define flapLevel10LED  4  // Activated by Switch 2 (only if Switch 1 is ON)
#define flapLevel11LED  5  // Activated by Switch 3 (only if Switch 2 is ON)
#define flapLevel12LED  6 

#define flapSwitchLED2 7  // Status LED for Switch 2 (Blinks if Switch 1 is OFF)
#define flapSwitchLED3  8 // Status LED for Switch 3 (Blinks if Switch 2 is OFF)
#define flapSwitchLED4  9



void setup() {
    pinMode(flapSwitch1, INPUT_PULLUP);
    pinMode(flapSwitch2, INPUT_PULLUP);
    pinMode(flapSwitch3, INPUT_PULLUP);
	pinMode(flapSwitch4, INPUT_PULLUP);
    
    pinMode(flapLevel8LED, OUTPUT);
    pinMode(flapLevel9LED, OUTPUT);
    pinMode(flapLevel10LED, OUTPUT);
    pinMode(flapLevel11LED, OUTPUT);
    pinMode(flapLevel12LED, OUTPUT);
    
    pinMode(flapSwitchLED2, OUTPUT);
    pinMode(flapSwitchLED3, OUTPUT);
	pinMode(flapSwitchLED4, OUTPUT);

    // Start with the first LED on
  digitalWrite(flapLevel8LED, LOW);

}

void loop() {
    bool s1 = !digitalRead(flapSwitch1);  // Active LOW
    bool s2 = !digitalRead(flapSwitch2);
    bool s3 = !digitalRead(flapSwitch3);
    bool s4 = !digitalRead(flapSwitch4);
  
  
  
    // flap LED logic
	if (s4 && s3 && s2 && s1) {
        digitalWrite(flapLevel8LED, HIGH);
        digitalWrite(flapLevel9LED, HIGH);
        digitalWrite(flapLevel10LED, HIGH);
        digitalWrite(flapLevel11LED, HIGH);
        digitalWrite(flapLevel12LED, LOW);
    } else if (s3 && s2 && s1) {
        digitalWrite(flapLevel8LED, HIGH);
        digitalWrite(flapLevel9LED, HIGH);
        digitalWrite(flapLevel10LED, HIGH);
        digitalWrite(flapLevel11LED, LOW);
        digitalWrite(flapLevel12LED, HIGH);
    } else if (s2 && s1) {
        digitalWrite(flapLevel8LED, HIGH);
        digitalWrite(flapLevel9LED, HIGH);
        digitalWrite(flapLevel10LED, LOW);
        digitalWrite(flapLevel11LED, HIGH);
        digitalWrite(flapLevel12LED, HIGH);
    } else if (s1) {
        digitalWrite(flapLevel8LED, HIGH);
        digitalWrite(flapLevel9LED, LOW);
        digitalWrite(flapLevel10LED, HIGH);
        digitalWrite(flapLevel11LED, HIGH);
        digitalWrite(flapLevel12LED, HIGH);
    } else {
        digitalWrite(flapLevel8LED, LOW);
        digitalWrite(flapLevel9LED, HIGH);
        digitalWrite(flapLevel10LED, HIGH);
        digitalWrite(flapLevel11LED, HIGH);
        digitalWrite(flapLevel12LED, HIGH);
    }

    // Handle LED5 (Switch 2 status)
    if (s2) {
        if (s1) {
            digitalWrite(flapSwitchLED2, LOW);  // Solid ON if Switch 1 is ON
        } else {
            blinkLED(flapSwitchLED2);  // Blink if Switch 1 is OFF
        }
    } else {
        digitalWrite(flapSwitchLED2, HIGH);
    }

    // Handle LED6 (Switch 3 status)
    if (s3) {
        if (s2 && s1) {
            digitalWrite(flapSwitchLED3, LOW);  // Solid ON if Switch 2 is ON
        } else {
            blinkLED1(flapSwitchLED3);  // Blink if Switch 2 is OFF
        }
    } else {
        digitalWrite(flapSwitchLED3, HIGH);
    }
	
	    // Handle LED6 (Switch 4 status)
    if (s4) {
        if (s3 && s2 && s1) {
            digitalWrite(flapSwitchLED4, LOW);  // Solid ON if Switch 2 is ON
        } else {
            blinkLED2(flapSwitchLED4);  // Blink if Switch 2 is OFF
        }
    } else {
        digitalWrite(flapSwitchLED4, HIGH);
    }
	
}


// Function to blink an LED
void blinkLED2(int ledPin) {
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
