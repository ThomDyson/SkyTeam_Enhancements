const int switch1 = 2;  // Switch 1 (must be ON before Switch 2)
const int switch2 = 3;  // Switch 2 (must be ON before Switch 3)
const int switch3 = 4;  // Switch 3 (must be ON before Switch 4)
const int switch4 = 11;  // Switch 4 

const int led1 = 5;  // Default LED (ON when no switch is active)
const int led2 = 6;  // Activated by Switch 1
const int led3 = 7;  // Activated by Switch 2 (only if Switch 1 is ON)
const int led4 = 8;  // Activated by Switch 3 (only if Switch 2 is ON)
const int led7 = 12;  // Activated by Switch 4 (only if Switch 3 is ON)

const int led5 = 9;  // Status LED for Switch 2 (Blinks if Switch 1 is OFF)
const int led6 = 10; // Status LED for Switch 3 (Blinks if Switch 1 or 2 is OFF)
const int led8 = A1; // Status LED for Switch 4 (Blinks if Switch 1 of 2 or 3 is OFF)


void setup() {
    pinMode(switch1, INPUT_PULLUP);
    pinMode(switch2, INPUT_PULLUP);
    pinMode(switch3, INPUT_PULLUP);
    pinMode(switch4, INPUT_PULLUP);
    
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led7, OUTPUT);
    
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(led8, OUTPUT);

}

void loop() {
    bool s1 = !digitalRead(switch1);  // Active LOW
    bool s2 = !digitalRead(switch2);
    bool s3 = !digitalRead(switch3);
    bool s4 = !digitalRead(switch4);
  
  
    // Main LED logic
    if (s4 && s3 && s2 && s1) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led7, LOW);
    } else if (s3 && s2 && s1) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        digitalWrite(led7, HIGH);
    } else if (s2 && s1) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        digitalWrite(led7, HIGH);
    } else if (s1) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led7, HIGH);
    } else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led7, HIGH);
    }

    // Handle LED5 (Switch 2 status)
    if (s2) {
        if (s1) {
            digitalWrite(led5, LOW);  // Solid ON if Switch 1 is ON
        } else {
            blinkLED1(led5);  // Blink if Switch 1 is OFF
        }
    } else {
        digitalWrite(led5, HIGH);
    }

    // Handle LED6 (Switch 3 status)
    if (s3) {
        if (s2 && s1) {
            digitalWrite(led6, LOW);  // Solid ON if Switch 2 is ON
        } else {
            blinkLED2(led6);  // Blink if Switch 2 is OFF
        }
    } else {
        digitalWrite(led6, HIGH);
    }

    // Handle LED8 (Switch 3 status)
    if (s4) {
        if (s3 && s2 && s1) {
            digitalWrite(led8, LOW);  // Solid ON if Switch 3 is ON
        } else {
            blinkLED3(led8);  // Blink if Switch 3 is OFF
        }
    } else {
        digitalWrite(led8, HIGH);
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
void blinkLED3(int ledPin) {
    static unsigned long previousMillis = 0;
    static bool ledState = false;
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 500) {  // Blink every 500ms
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
    }
}

