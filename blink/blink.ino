#define BLED 9
#define GLED 10
#define RLED 11
#define BUTTON 2

boolean lastButton = LOW;
boolean currentButton = LOW;

int ledMode = 0;

void setup() {
    // debug
    Serial.print("ledMode: ");
    Serial.println(ledMode);
    pinMode(BLED, OUTPUT);
    pinMode(GLED, OUTPUT);
    pinMode(RLED, OUTPUT);
    pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last) {
    boolean current = digitalRead(BUTTON);
    if (last != current) {
        delay(5);
        current = digitalRead(BUTTON);
    }
    return current;
}

void setMode(int mode) {
    if (mode == 1) {  // red
        digitalWrite(RLED, LOW);
        digitalWrite(GLED, HIGH);
        digitalWrite(BLED, HIGH);
    } else if (mode == 2) {  // green
        digitalWrite(RLED, HIGH);
        digitalWrite(GLED, LOW);
        digitalWrite(BLED, HIGH);
    } else if (mode == 3) {  // blue
        digitalWrite(RLED, HIGH);
        digitalWrite(GLED, HIGH);
        digitalWrite(BLED, LOW);
    } else if (mode == 4) {  // purple (red + blue)
        analogWrite(RLED, 127);
        analogWrite(GLED, 255);
        analogWrite(BLED, 127);
    } else if (mode == 5) {  // teal (blue + green)
        analogWrite(RLED, 255);
        analogWrite(GLED, 127);
        analogWrite(BLED, 127);
    } else if (mode == 6) {  // orange (green + red)
        analogWrite(RLED, 127);
        analogWrite(GLED, 127);
        analogWrite(BLED, 255);
    } else if (mode == 7) {  // white
        analogWrite(RLED, 170);
        analogWrite(GLED, 170);
        analogWrite(BLED, 170);
    } else {  // off
        digitalWrite(RLED, HIGH);
        digitalWrite(GLED, HIGH);
        digitalWrite(BLED, HIGH);
    }
}

void loop() {
    currentButton = debounce(lastButton);

    if (lastButton == LOW && currentButton == HIGH) {
        ledMode++;
    }

    lastButton = currentButton;

    if (ledMode == 8) {
        ledMode = 0;
    }
    setMode(ledMode);
}
