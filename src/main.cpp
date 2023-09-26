#include <Arduino.h>
#include <SSD1306.h>
SSD1306   display(0x3c,4,5, GEOMETRY_128_32);

                      int val=0;
double data[100];
double ema=data[0];
int datasize;
double alpha;
int size=0;
char valStr[100];
char emaStr[100];

void setup(){
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
}

void loop(){
    val=analogRead(0);
    data[size]=val;
    alpha=0.2;
    ema=alpha*data[size]+(1-alpha)*ema;
    size++;
    Serial.print("val:");
    Serial.println(val);
    Serial.print("ema:");
    Serial.println(ema);
    snprintf(valStr, sizeof(valStr), "%d", val);
    snprintf(emaStr, sizeof(emaStr), "%f", ema);
    display.clear();
    display.drawString(0,10,"val:");
    display.drawString(30,10,valStr);
    display.drawString(50,10,"ema:");
    display.drawString(90,10,emaStr);
    display.display();
    delay(1000);
}