/*
Author: Yujie Wu 
11/18/23
Description:
COB LED strip controller
ru,gu,bu pins controls the upper led strip
rl,gl,bl pins controls the lower led strip
*/

#define ru 9
#define gu 10
#define bu 11
#define rl 3
#define gl 5
#define bl 6

// red 255, 0, 0
// orange 255, 102, 0
// green 0, 255, 0
// indigo 3, 244, 252
// blue 0, 0, 255
// purple 191, 0, 255
// white 220, 220, 220

int colorR[] = {255,255,0,3,0,191,220};
int colorG[] = {0,102,255,244,0,0,220};
int colorB[] = {0,0,0,252,255,255,220};
int i = 0; 
int j = 0; 

void setup() {
  pinMode(ru, OUTPUT);
  pinMode(gu, OUTPUT);
  pinMode(bu, OUTPUT);
  pinMode(rl, OUTPUT);
  pinMode(gl, OUTPUT);
  pinMode(bl, OUTPUT);
}

void loop() {

  while(i==j){
    i = random(0,7);
    j = random(0,7);
  }
  fadeInUpper(colorR[i], colorG[i], colorB[i], 5);
  fadeInLower(colorR[j], colorG[j], colorB[j], 5);
  delay(180000);
  fadeOutUpper(colorR[i], colorG[i], colorB[i], 5);
  fadeOutLower(colorR[j], colorG[j], colorB[j], 5);
  turnOff();
  delay(1000);

  i = 0;
  j = 0;

  // // Phase 1
  // // purple 191, 0, 255
  // fadeInUpper(191, 0, 255, 5);
  // // blue 0, 0, 255
  // fadeInLower(0, 0, 255, 5);
  // // remain turned on for n/1000 seconds
  // delay(180000);
  // fadeOutUpper(191, 0, 255, 5);
  // fadeOutLower(0, 0, 255, 5);
  // turnOff();
  // delay(1000);

  // // Phase 2
  // // green 0, 255, 0
  // fadeInUpper(0, 255, 0, 5);
  // // orange 255, 102, 0
  // fadeInLower(255, 102, 0, 5);
  // // remain turned on for n/1000 seconds
  // delay(180000);
  // fadeOutUpper(0, 255, 0, 5);
  // fadeOutLower(255, 102, 0, 5);
  // turnOff();
  // delay(1000);
 

}

//takes rgb value lit the upper led strip
void turnOnUpper(int r, int g, int b){
  analogWrite(ru, r);
  analogWrite(gu, g);
  analogWrite(bu, b);
}

 // turn on lower led strip
void turnOnLower(int r, int g, int b){
  analogWrite(rl, r);
  analogWrite(gl, g);
  analogWrite(bl, b);
}


void fadeInUpper(int r, int g, int b, int timing){
  int fadeSpeed = 0;
  while (fadeSpeed <= max(max(r,g),b)){
    if (fadeSpeed <= r) analogWrite(ru, fadeSpeed);
    if (fadeSpeed <= g) analogWrite(gu, fadeSpeed);
    if (fadeSpeed <= b) analogWrite(bu, fadeSpeed);
    fadeSpeed++;
    delay(timing);
  }
}

void fadeInLower(int r, int g, int b, int timing){
  int fadeSpeed = 0;
  while (fadeSpeed <=max(max(r,g),b)){
    if (fadeSpeed <= r) analogWrite(rl, fadeSpeed);
    if (fadeSpeed <= g) analogWrite(gl, fadeSpeed);
    if (fadeSpeed <= b) analogWrite(bl, fadeSpeed);
    fadeSpeed++;
    delay(timing);
  }
}

void fadeOutUpper(int r, int g, int b, int timing){
  int fadeSpeed = 0;
  while (fadeSpeed <= max(max(r,g),b)){
    if (r-fadeSpeed > 0) analogWrite(ru, r-fadeSpeed);
    if (g-fadeSpeed > 0) analogWrite(gu, g-fadeSpeed);
    if (b-fadeSpeed > 0) analogWrite(bu, b-fadeSpeed);
    fadeSpeed++;
    delay(timing);
  }
}

void fadeOutLower(int r, int g, int b, int timing){
  int fadeSpeed = 0;
  while (fadeSpeed <= max(max(r,g),b)){
    if (r-fadeSpeed > 0) analogWrite(rl, r-fadeSpeed);
    if (g-fadeSpeed > 0) analogWrite(gl, g-fadeSpeed);
    if (b-fadeSpeed > 0) analogWrite(bl, b-fadeSpeed);
    fadeSpeed++;
    delay(timing);
  }
}

void turnOff(){
  analogWrite(ru, 0);
  analogWrite(gu, 0);
  analogWrite(bu, 0);
  analogWrite(rl, 0);
  analogWrite(gl, 0);
  analogWrite(bl, 0);
}
