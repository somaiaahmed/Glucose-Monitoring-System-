const int PT1_PIN = A0; // phototransistor 1 pin (blue)
const int PT2_PIN = A1; // phototransistor 2 pin (green)

const int led = 3; // led pin

double y;

// function to convert raw analog value to NIR absorbance
double analogToGlucose(double analogValue) {
  y = (3*pow(10,-5)) *pow(analogValue,2) + 0.2903*analogValue - 4.798;
  return y; //y is the glucose concentratoin.
}

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(led,HIGH);
  
  // read raw analog values from phototransistors
  int pt1Value = analogRead(PT1_PIN);
  int pt2Value = analogRead(PT2_PIN);
  
  //taking the average of the raw data
  double averageValue = (pt1Value+pt2Value)/2.0;

  // calculate glucose concentration from voltage
  double glucoseConcentration = analogToGlucose(averageValue);

  // display glucose concentration
  Serial.print("Glucose concentration: ");
  Serial.print(glucoseConcentration);
  Serial.println(" mg/dL");

  // delay before taking the next measurement
  delay(1000);
}

/*
// for testing purpose
void loop() {
  digitalWrite(led,HIGH);
  Serial.println("Enter a value:");
  
  // wait for user input
  while (Serial.available() == 0) {
    // do nothing
  }
  // read the user input
  String analogValue = Serial.readString();
  // convert the input to an integer
  double value = analogValue.toDouble();
  
  // read raw analog values from phototransistors
  int pt1Value = analogRead(PT1_PIN);
  int pt2Value = analogRead(PT2_PIN);
  
  //taking the average of the raw data
  float averageValue = (pt1Value+pt2Value)/2.0;

  // calculate glucose concentration from voltage
  double glucoseConcentration = analogToGlucose(value);

  // display glucose concentration
  Serial.print("Glucose concentration: ");
  Serial.print(glucoseConcentration);
  Serial.println(" mg/dL");

  // delay before taking the next measurement
  delay(1000);
}*/

