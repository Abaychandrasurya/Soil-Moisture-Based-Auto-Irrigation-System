const int soilMoisturePin = A0; 
const int relayPin = 7;          

const int dryThreshold = 600;    

void setup() {
  Serial.begin(9600);
  pinMode(soilMoisturePin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); 
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);
  if (soilMoistureValue > dryThreshold) {
    digitalWrite(relayPin, LOW); 
    Serial.println("Pump ON");
  } else {
    digitalWrite(relayPin, HIGH); 
    Serial.println("Pump OFF");
  }
  delay(5000); 
}
