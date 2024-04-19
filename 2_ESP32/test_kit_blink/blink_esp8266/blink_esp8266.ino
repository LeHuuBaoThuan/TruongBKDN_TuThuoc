#define LED_RESULT 16
#define LED_SEND   14

void setup() 
{
  pinMode(LED_RESULT, OUTPUT);
  pinMode(LED_SEND,   OUTPUT);

  digitalWrite(LED_RESULT,  HIGH);
  digitalWrite(LED_SEND,    HIGH);
}

void loop() 
{
  digitalWrite(LED_RESULT, HIGH );
  delay(1000);
  digitalWrite(LED_RESULT, LOW  );
  delay(1000);
}