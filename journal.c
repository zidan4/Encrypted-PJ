// Simplified Arduino Alternator Cutoff
int throttlePin = A0;
int relayPin = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Default ON
}

void loop() {
  int throttle = analogRead(throttlePin);
  if (throttle < 100) {  // Coasting
    digitalWrite(relayPin, HIGH);  // Charge
  } else {
    digitalWrite(relayPin, LOW);   // Cut
  }
}
