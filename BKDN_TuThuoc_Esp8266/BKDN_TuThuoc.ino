  /*
    Rui Santos
    Complete project details at our blog.
      - ESP32: https://RandomNerdTutorials.com/esp32-firebase-realtime-database/
      - ESP8266: https://RandomNerdTutorials.com/esp8266-nodemcu-firebase-realtime-database/
    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
    Based in the RTDB Basic Example by Firebase-ESP-Client library by mobizt
    https://github.com/mobizt/Firebase-ESP-Client/blob/main/examples/RTDB/Basic/Basic.ino
  */

  #include <Arduino.h>
  #if defined(ESP32)
    #include <WiFi.h>
  #elif defined(ESP8266)
    #include <ESP8266WiFi.h>
  #endif
  #include <Firebase_ESP_Client.h>

  //Provide the token generation process info.
  #include "addons/TokenHelper.h"
  //Provide the RTDB payload printing info and other helper functions.
  #include "addons/RTDBHelper.h"

  // Insert your network credentials
  #define WIFI_SSID "PHONG TRO"
  #define WIFI_PASSWORD "Viettel4g"

  // Insert Firebase project API Key
  #define API_KEY "AIzaSyBck_9xCX0zUvnnVmRT7KmOVZLKVe8nkdk"

  // Insert RTDB URLefine the RTDB URL */
  #define DATABASE_URL "https://faceproject-b3c27-default-rtdb.firebaseio.com/" 

  //Define Firebase Data object
  FirebaseData fbdo;

  FirebaseAuth auth;
  FirebaseConfig config;

#define PWM1 13
#define PWM2 23
#define PWM3 19
#define PWM4 18
#define PWM5 5
#define PWM6 4
#define PWM7 2
  unsigned long previousMillis = 0;
  const long timequay = 450;  // Khoảng thời gian quay động cơ

  unsigned long sendDataPrevMillis = 0;
  // float floatValue; 
  bool signupOK = false;

  uint8_t STT = 0;
  uint8_t old_STT[7] = {0};
  uint8_t Current_STT[7] = {0};
  uint8_t Set_motor[7] = {0};
  
  void PWM(int PWMX);
  void setup() {
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");

    while (WiFi.status() != WL_CONNECTED) 
    {
      Serial.print(".");
      delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

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

    int pwmPins[] = { PWM1, PWM2, PWM3, PWM4, PWM5, PWM6, PWM7 };
    int numPins = sizeof(pwmPins) / sizeof(pwmPins[0]);
    for (int i = 0; i < numPins; i++) 
    {
      pinMode(pwmPins[i], OUTPUT);
      digitalWrite(pwmPins[i], HIGH);
    }
  }

  void loop() {
    if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 1000 || sendDataPrevMillis == 0)) 
    {
      sendDataPrevMillis = millis();
      for(STT = 1; STT <= 7; STT++)
      {
        if (Firebase.RTDB.getInt(&fbdo, "/User/" + String(STT) + "/time")) 
        {
          if (fbdo.dataType() == "int") 
          {
            // Serial.println(fbdo.intData());
            Current_STT[STT - 1] = fbdo.intData();
          }
        }
        else 
        {
          Serial.println("Khong dc");
        }
      }
    }
 /*Sosanh*/
    for(uint8_t i  = 0; i <= 6; i++)
    {
      if(Current_STT[i] < old_STT[i])
      {
        Set_motor[i] = 1;
      }
      else
      {
        Set_motor[i] = 0;
      }
      old_STT[i] = Current_STT [i];
    }
  /*serial*/
    for(uint8_t j = 0; j <= 6; j++)
    {
      Serial.print("Motor[" + String(j) + "]: ");
      Serial.print(String(Set_motor[j]) + " ");

      Serial.print("Current_STT ["+ String(j) +"] : ");
      Serial.print(String(Current_STT[j]) + " ");

      Serial.print("old_STT ["+ String(j) +"] : ");
      Serial.print(String(old_STT[j]) + " ");

      Serial.println();
      Serial.println();
    }
    if(Set_motor[0] == 1)
    {
      PWM(PWM1);
    }
    if(Set_motor[1] == 1)
    {
      PWM(PWM2);
    }
    if(Set_motor[2] == 1)
    {
      PWM(PWM3);
    }
    if(Set_motor[3] == 01)
    {
      PWM(PWM4);
    }
    if(Set_motor[4] == 01)
    {
      PWM(PWM5);
    }
    if(Set_motor[5] == 01)
    {
      PWM(PWM6);
    }
    if(Set_motor[6] == 01)
    {
      PWM(PWM7);
    }
  }

  void PWM(int PWMX) 
  {
    Serial.print("Chay");
    digitalWrite(PWMX, LOW);
    delay(timequay);
    digitalWrite(PWMX, HIGH);
  }