class LED{ 
public: 
  LED(int pin): pin(pin){
    pinMode(pin, OUTPUT);
    estado = LOW;
  }
  
  void encenderLed(){
    digitalWrite(pin, HIGH);
    estado = HIGH;
  }
  
  void apagarLed(){
    digitalWrite(pin, LOW);
    estado = LOW;
  }
  
  void parpadearLed(int intervalo){
    encenderLed();
    delay(intervalo / 2);
    apagarLed();
    //delay(intervalo / 2);
  }
  
  int obtenerEstado(){
    return estado;
  }
  
private:
  int pin;
  int estado;
};

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

// Sensor Ultrasonico inicializando PINES
int echoPin = 13;
int triggerPin = 12;

int inches = 0;
int cm = 0;

// creando objetos LED

LED ledR1(14);
LED ledR2(27);

LED ledA1(26);
LED ledA2(25);

LED ledV1(33);
LED ledV2(32);

void setup(){
  Serial.begin(9600);
}

void loop(){
  cm = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);
  inches = (cm / 2.54);
  
  if(cm <= 1020 and cm > 50){
    ledR1.encenderLed();
    ledR2.encenderLed();
  } else {
    ledR1.apagarLed();
    ledR2.apagarLed();
  }
  if(cm <= 50 and cm >= 20){
    ledA1.encenderLed();
    ledA2.encenderLed();
  } else {
    ledA1.apagarLed();
    ledA2.apagarLed();
  }
  if(cm < 20 and cm > 5){
    ledV1.encenderLed();
    ledV2.encenderLed();
  } else {
    ledV1.apagarLed();
    ledV2.apagarLed();
  }

  if(cm <= 5 and cm > 2){
    ledR1.parpadearLed(500);
    ledR2.parpadearLed(500);
    ledA1.parpadearLed(500);
    ledA2.parpadearLed(500);
    ledV1.parpadearLed(500);
    ledV2.parpadearLed(500);
  }


  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
}