#define BLUE 9
#define GREEN 10
#define RED 11

#define LOWER_BOUND 26
#define UPPER_BOUND 27

int tmp36Value = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
}

void loop() {
    tmp36Value = analogRead(A0);


    // calculate the temperature from tmp36
    float voltage = tmp36Value * 5.0;
    voltage /= 1024.0;
    float temperatureC = (voltage - 0.5) * 100;

    Serial.println(temperatureC);

    if (temperatureC < LOWER_BOUND) {
        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, HIGH);
        digitalWrite(BLUE, LOW);
    } else if (temperatureC > UPPER_BOUND) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, HIGH);
        digitalWrite(BLUE, HIGH);
    } else {
        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, HIGH);
    }
}