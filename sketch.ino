int switchPin = 3; //кнопка
int whitePin = 0; // светодиод для режима 1
int redPin = 1;// светодиод для режима 2
int whitePin2 = 2;
int mode = 0; // 0 off, 1 white, 2 red blink 
boolean lastButton = LOW; 
boolean currentButton = LOW;
int whiteState1 = 0; //состояние белого 1
int whiteState2 = 0; //состояние белого 2
int redState = LOW;  // состояние красного
long previousMillis = 0;
long interval = 1000;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(whitePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(whitePin2, OUTPUT);
  // Serial.begin(9600); //для отладки
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if (last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}
void blink(void){
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (redState == LOW)
      redState = HIGH;
    else
      redState = LOW;

    // set the LED with the redState of the variable:

  }

}

void loop()
{
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    mode++;
    if (mode >= 4) mode = 0;
  }
  lastButton = currentButton;
  switch (mode) {
  case 0:
    whiteState1 = 0;
    whiteState2 = 0;
    redState = LOW;
    break; 
  case 1:
    whiteState1 = 1;
    redState = LOW;
    whiteState2 = 0;
    break;
  case 2:
    whiteState1 = 0;
    whiteState2 = 0;
    blink();
    break;
  case 3:
    whiteState1 = 0;
    redState = LOW;
    whiteState2 = 1;
    break;

  }  
  digitalWrite(redPin, redState);
  digitalWrite(whitePin, whiteState1);
  digitalWrite(whitePin2, whiteState2);
  //Serial.println(mode);

}