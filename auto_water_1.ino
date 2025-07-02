// Pin definitions
const int soilMoisturePin = A0;  // Soil sensor analog output
const int relayPin = 7;          // Relay control pin

// Thresholds (tweak according to your soil)
const int dryThreshold = 600;    // Value above this is considered dry soil

void setup() {
  Serial.begin(9600);
  pinMode(soilMoisturePin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Keep pump off initially (active LOW relay)
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);
  if (soilMoistureValue > dryThreshold) {
    // Soil is dry -> Turn on pump
    digitalWrite(relayPin, LOW);  // Activate relay (pump ON)
    Serial.println("Pump ON");
  } else {
    // Soil is wet enough -> Turn off pump
    digitalWrite(relayPin, HIGH); // Deactivate relay (pump OFF)
    Serial.println("Pump OFF");
  }
  delay(5000); // Wait 5 seconds before next reading
}