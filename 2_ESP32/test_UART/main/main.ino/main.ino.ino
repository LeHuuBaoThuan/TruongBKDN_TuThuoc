#include <SoftwareSerial.h>

#define TX  (12)
#define RX  (13)

// SoftwareSerial mySerial = SoftwareSerial(RX, TX);
SoftwareSerial mySerial(RX, TX); // RX, TX

long lastUART = 0;

void Read_Uart();    // UART STM

String LED1 = "OFF", LED2 = "OFF";
void setup()
{
  Serial.begin(9600);
  mySerial.begin(115200);

  Serial.println("UART Start");

  lastUART = millis();
}
void loop()
{
  // Read_Uart();
  if (millis() - lastUART > 1000)
  {
    mySerial.print("1ON2ON3OFF4\n\r");
    Serial.println("Truyen : 1ON2ON3OFF4");
    lastUART = millis();
  }
}
void Read_Uart()
{
  String st = "";
  while (mySerial.available())
  {
    char inChar = (char)mySerial.read();
    st +=  inChar;
    if (inChar == 'C')
    {
      Serial.println("Nhan : " + st);
      int A = st.indexOf("A");
      int B = st.indexOf("B");
      int C = st.indexOf("C");

      LED1 = st.substring(A + 1, B);
      LED2 = st.substring(B + 1, C);
      Serial.println("LED1 : "+LED1+ "  LED2: "+  LED2 );
      break;
    }
  }
}