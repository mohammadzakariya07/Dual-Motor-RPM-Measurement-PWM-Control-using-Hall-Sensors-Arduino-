const int hallSensorPin1 = 2;
const int hallSensorPin2 = 3;
const int pwmOutputPin1 = 9;
const int pwmOutputPin2 = 10;

volatile unsigned int pulseCount1 = 0;
volatile unsigned int pulseCount2 = 0;

unsigned long previousMillis = 0;
const unsigned long interval = 1000;
const unsigned int pulsesPerRevolution = 1;

void setup() {
  Serial.begin(9600);

  pinMode(hallSensorPin1, INPUT_PULLUP);
  pinMode(hallSensorPin2, INPUT_PULLUP);
  pinMode(pwmOutputPin1, OUTPUT);
  pinMode(pwmOutputPin2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(hallSensorPin1), countPulse1, FALLING);
  attachInterrupt(digitalPinToInterrupt(hallSensorPin2), countPulse2, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    unsigned int rpm1 = (pulseCount1 * 60) / pulsesPerRevolution;
    pulseCount1 = 0;

    unsigned int rpm2 = (pulseCount2 * 60) / pulsesPerRevolution;
    pulseCount2 = 0;

    Serial.println("Welcome !");
    Serial.println("Written by Mohammad Zakariya");

    Serial.print("Motor 1 RPM: ");
    Serial.print(rpm1);
    Serial.print(" | Motor 2 RPM: ");
    Serial.println(rpm2);

    int pwmValue1 = map(rpm1, 0, 10000, 0, 255);
    int pwmValue2 = map(rpm2, 0, 10000, 0, 255);

    analogWrite(pwmOutputPin1, pwmValue1);
    analogWrite(pwmOutputPin2, pwmValue2);
  }
}

void countPulse1() {
  pulseCount1++;
}

void countPulse2() {
  pulseCount2++;
}
