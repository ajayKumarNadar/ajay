void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT); pinMode(8, OUTPUT); // Moisture Sensor
  pinMode(12, OUTPUT); // Water Pump
  pinMode(13, OUTPUT); // Water Level Sensor
  pinMode(4, OUTPUT); // Buzer
}

void loop() {
  //    Moisture Sensor 1,   Moisture Sensor 2,   Water level Sensor
  int m1 = analogRead(A1), m2 = analogRead(A2), water_level = analogRead(A3);

  Serial.println(m1);
  Serial.println(m2);
  Serial.println(water_level);

  digitalWrite(7, HIGH); digitalWrite(8, HIGH); digitalWrite(13, HIGH);// Switch On all Sensors

  if (1000 < (m1 + m2) < 2000) // Soil is Dry
  { 
    Serial.println("Soil is Dry!"); digitalWrite(12, HIGH); // Switch on Pump

    if (water_level < 512) // Container is empty
    { 
      Serial.println("The water in container is almost empty!");
      digitalWrite(4, HIGH); // Trigger the buzzer!
    }
    digitalWrite(7, LOW); digitalWrite(8, LOW); digitalWrite(13, LOW); // Switch off all sensors  
    delay(60000); // Wait for 1 minute
  } 
  else // Soil is Wet  
  {   
    Serial.println("Soil is Wet");
    digitalWrite(7, LOW); digitalWrite(8, LOW); // Switch off everything!
    digitalWrite(13, LOW); digitalWrite(12, LOW); digitalWrite(4, LOW); // Switch off everything!
    delay(3000000); // Wait for 30 minutes
  }
}