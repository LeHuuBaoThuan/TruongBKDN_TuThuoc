#include <Arduino.h>

#include <SoftwareSerial.h>

#define TX  (12)
#define RX  (13)

SoftwareSerial mySerial(RX, TX); // RX, TX

#if defined(ESP32)
#include <WiFi.h>

#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif



#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>


#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
// #define WIFI_SSID "Zone Six-19PNX-2G"
// #define WIFI_PASSWORD "19phamnhuxuong"


#define WIFI_SSID "PHONG TRO"
#define WIFI_PASSWORD "hoilamchi"

// Insert Firebase project API Key
#define API_KEY "AIzaSyC5tecz0gLaEPc8T6dMDWDKbq8vG0vQ5_c"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://iotk17thuan-default-rtdb.asia-southeast1.firebasedatabase.app/" 

#define L_ON_BOARD    2
#define L_TX    14
#define L_RX    16
//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long previousMillis = 0;
unsigned long sendDataPrevMillis = 0;
bool signupOK = false;

/*USER VARRIABLE*/
uint8_t STT = 0;
uint8_t old_STT[7] = {0};                 // Số thứ tự cũ của người dùng, được so sánh với stt hiện tại của người muốn sử dụng máy
uint8_t Current_STT[7] = {0};             // Số thứ tự hiện tại của người dùng muốn sử dụng máy

uint32_t String_2_Int[7] = {0};     // array chứa Pin của từng user
uint32_t Old_String_2_Int[7] = {0};     // array chứa Pin của từng user

void setup()
{
  Serial.begin(115200);

  mySerial.begin(115200);

  pinMode(L_ON_BOARD, OUTPUT);
  // Connect wiffi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  // End Connect wiffi

  /* Assign the api key (required) */
  config.api_key = API_KEY;
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
} // End Setup

void loop() 
{ 
  digitalWrite(L_ON_BOARD, !digitalRead(L_ON_BOARD));
  /* Nhận dữ liệu từ RDTB Firebase */
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 1000 || sendDataPrevMillis == 0)) 
  {
    sendDataPrevMillis = millis();
    Serial.println();
    Serial.println("**new**");
    for(STT = 1; STT <= 7; STT++)
    {
      if (Firebase.RTDB.getInt(&fbdo, "/User/" + String(STT) + "/timer")) 
      {
        if (fbdo.dataType() == "int") 
        {
          Serial.print("STT["+ String(STT) + "]  = " + String(fbdo.intData()) + " --");
          Current_STT[STT - 1] = fbdo.intData();
        }
        else Serial.println("ko nhan duoc timer ... ");
      }
      Serial.println("/////////////////////////////");
      if (Firebase.RTDB.getString(&fbdo, "/User/" + String(STT) + "/Pin"))
      {
        if (fbdo.dataType() == "string") 
        {
          String command = fbdo.stringData();
          Serial.print("Received Pin: ");
          // Serial.println(command);
          String_2_Int[STT-1] = fbdo.stringData().toInt();
          Serial.println(String_2_Int[STT-1]);      
        }
        else
        {
          Serial.println("ko nhan duoc Pin ... ");
        }        
      }
    }
  } /*END CHECK*/

  /*Sosanh*/
  Serial.println("down err");
  for(uint8_t i  = 0; i <= 6; i++)
  {
    /*Kich TT Relay*/
    if(Current_STT[i] != old_STT[i])     // nếu có người sài máy
    {
      digitalWrite(L_TX, !digitalRead(L_TX));
      
      /*handler: Motor[x]: x\n\r*/
      mySerial.print("Motor:" + String(i) + "\n\r");
    
      // /*serial*/
      // Serial.println();
      // Serial.println("**Nhan**");
      // Serial.print("Motor[" + String(i) + "]: ");
      // Serial.print(String(Set_motor[i]) + " ");

      // Serial.print("Current_STT ["+ String(i) +"] : ");
      // Serial.print(String(Current_STT[i]) + " ");

      // Serial.print("old_STT ["+ String(i) +"] : ");
      // Serial.println(String(old_STT[i]) + " ");

      // Serial.println("*******END********");
      // Serial.println();
    }
    else                                // nếu có người không sài máy,  stt_cur == stt_old
    {
      Serial.print("Not: " + String(i));
    }
    old_STT[i] = Current_STT[i];        // lưu giá trị cũ

    /*Đổi mã pin*/
    if(String_2_Int[i] != Old_String_2_Int[i])     // Đổi mã pin
    {
      digitalWrite(L_TX, !digitalRead(L_TX));
      
      /*handler: *NUM-PIN:x,abcde\n\r*/
      mySerial.print("*NUM-PIN:" + String(i+1) + "," + String(String_2_Int[i]) + "\n\r"); // gửi chuỗi mã Pin
    
      /*serial*/
      Serial.println();
      Serial.println("**Nhan**");
      Serial.print("PIN[" + String(i) + "]: 1");

      Serial.print("String_2_Int ["+ String(i) +"] : ");
      Serial.print(String(String_2_Int[i]) + " ");

      Serial.print("Old_String_2_Int ["+ String(i) +"] : ");
      Serial.println(String(Old_String_2_Int[i]) + " ");

      Serial.println("*******END********");
      Serial.println();
    }
    else                                // nếu có người không sài máy,  stt_cur == stt_old
    {
      Serial.print("Not");
    }
    Old_String_2_Int[i] = String_2_Int[i];        // lưu giá trị cũ
  }
}



   

