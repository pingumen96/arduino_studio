#define LED 9
#define PHOTORESISTOR A0
#define MIN_LIGHT 0
#define MAX_LIGHT 100

int val = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
}

void loop() {
    val = analogRead(PHOTORESISTOR);               // Read the light value
    val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);  // Map the light reading
    val = constrain(val, 0, 255);                  // Constrain light value
    analogWrite(LED, val);
    Serial.println(val);
}