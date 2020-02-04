#include "Audio.h"
#include "CloudSpeechClient.h"
#include "M5Stack.h"

void setup() {
  Serial.begin(115200);
  M5.begin();
  delay(500);
  Serial.println("\r\nRecord start!\r\n");
  Audio* audio = new Audio(ICS43434);
//  Audio* audio = new Audio(M5STACKFIRE);
  audio->Record();
  CloudSpeechClient* cloudSpeechClient = new CloudSpeechClient(USE_APIKEY);
  cloudSpeechClient->Transcribe(audio);
  delete cloudSpeechClient;
  delete audio;
}

void loop() {
}
