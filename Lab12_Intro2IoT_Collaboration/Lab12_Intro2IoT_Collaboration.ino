// === Automatic Room Light with Manual Override ===

const int lightSensorPin = A0;   // Photoresistor connected to A0
const int buttonPin = 2;         // Button connected to D2
const int ledPin = 9;            // LED (room light) connected to D9

const int darkThreshold = 500;   // Adjust based on ambient light conditions

bool isDark = false;
bool isButtonOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);  // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);
}

void loop() {
  isDark = isRoomDark();             // Light detection logic
  isButtonOn = isButtonActivated();  // Button-based manual override

  // Control the LED
  if (isDark || isButtonOn) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
  }

  delay(200); // basic debounce + sampling interval
}

// ===============================
// Light Detection – Student 1
bool isRoomDark() {
  int lightLevel = analogRead(lightSensorPin);
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  if (isDark == 1) {
    Serial.print("Room is Dark");
  } else {
    Serial.print("Room is Bright");
  }
  // TODO: Fix this logic so it returns true when it's dark
  if (lightLevel < darkThreshold) {
    return true;
  } else {
    return false;
  }
  
  return false; // <-- incorrect for now
}

// ===============================
// Manual Switch Control – Student 2
bool isButtonActivated() {
  bool state = digitalRead(2);
  
  

  // TODO: Fix this logic and print the correct status
  // Button is normally HIGH
  if (state == LOW) {
    Serial.print("Button:ON");
    // Button not pressed
    Serial.print("Button:OFF");
    return true;
  } else  {
    // Button pressed
<<<<<<< Updated upstream
    Serial.print("Button:OFF");
=======
    Serial.print("Button:ON");
>>>>>>> Stashed changes
    return false;
  }

  // HINT: Serial.print should say "ON" or "OFF" too
}
