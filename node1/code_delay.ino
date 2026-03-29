//Used delay in this code but it slows down the monitoring behaviour of the sensor so replaced it with millis in the code for hardware implementation. Used this for simulation on Proteus
int vibration = 13;
int hazard = 12;
int warning = 10;
int safe = 8;
int load = A4;
int speed = A5;
int lm_temp = A1;

void setup() {
  pinMode(hazard,OUTPUT);
  pinMode(warning,OUTPUT);
  pinMode(safe,OUTPUT);
  pinMode(vibration,INPUT);
  pinMode(load,INPUT);
  pinMode(speed,INPUT);
  pinMode(lm_temp,INPUT);
  Serial.begin(9600);
}

void loop() {
  //Sensor Reading Stage and Displaying it on Serial Monitor
  int vib_value = digitalRead(vibration);
  int load_value = analogRead(load);
  int speed_value = analogRead(speed);
  int lm_temp_value = analogRead(lm_temp);
  float voltage = lm_temp_value * (5.0 / 1023.0);
  float temperature = voltage * 100;
  Serial.print("Machine Vibration: ");
  Serial.println(vib_value);
  Serial.print("Machine Load: ");
  Serial.println(load_value);
  Serial.print("Machine Motor Speed: ");
  Serial.println(speed_value);
  Serial.print("Machine Heating: ");
  Serial.println(temperature);
  delay(1000);
  //Condition based LED alert System
  //Hazardous / Dangerous Conditions Logic
  if(vib_value == 1 || load_value >= 700 || speed_value >= 700 || temperature > 40)
  {
    digitalWrite(hazard,HIGH);
    digitalWrite(safe,LOW);
    digitalWrite(warning,HIGH);
    delay(50);
    digitalWrite(warning,LOW);
    delay(50);
    Serial.println("Dangerous Production Line Conditions Detected !! Please check the Production Line Machine Conditions ");
  }
  //Warning Conditions Logic
  else if(vib_value == 1 || load_value >= 600 || speed_value >= 600 || temperature > 35)
  {
    digitalWrite(hazard,LOW);
    digitalWrite(safe,LOW);
    int i;
    for(i=0;i<255;i++)
    {
      analogWrite(warning,i);
      delay(5);
    }
    for(i=255;i>=0;i--)
    {
      analogWrite(warning,i);
      delay(5);
    }
    Serial.println("Warning Sign !! Some issues with machine and production line detected. Please check to avoid hazards ");
  }
  //Safe Working Conditions Logic
  else
  {
    digitalWrite(safe,HIGH);
    digitalWrite(warning,LOW);
    digitalWrite(hazard,LOW);
    Serial.println("Safe Production Line Conditions. Machines Operating Smoothly");
  }
  delay(1000);
}
