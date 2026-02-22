// Motor Driver Pins
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  StopMotors();   // Ensure motors are stopped initially
}

void loop() {
  while (Serial.available() > 0) {
    char command = Serial.read();

    switch(command) {

      case 'F': Forward(); break;   // Move Forward
      case 'B': Backward(); break;  // Move Backward
      case 'L': Left(); break;      // Turn Left
      case 'R': Right(); break;     // Turn Right
      case 'S': StopMotors(); break; // Stop
    }
  }
}

// ========= MOTOR FUNCTIONS =========

void Forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void StopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
