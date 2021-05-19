import processing.serial.*;
import java.awt.event.KeyEvent;
import java.io.IOException;

Serial myPort;
int iAngle=90;
int iDistance;

void setup() {
    size(1300, 800);
    smooth();
    
    myPort = new Serial(this, Serial.list()[0], 9600);
    myPort.clear();
    myPort.bufferUntil('\n');
}

void draw() 
{
    background(255);
    DrawLine();
    DrawObject();
}

void serialEvent (Serial myPort) 
{
    try {
        String data = myPort.readStringUntil('\n');
            if (data == null) {
            return;
        }
        String distance = data.substring(0, data.length()-1);
        iDistance = StringToInt(distance);
    } catch(RuntimeException e) {}
}

void DrawLine(){
  fill(0);
  dottedLine(0, height/2, width, height/2,40);
}

void DrawObject() 
{ 
    noStroke();
    textSize(32);
    fill(0,255,0);

    println(iDistance);
    float x = map(iDistance,2,50,0,width);
    
    if(iDistance>15&&iDistance<35)
    {  fill(255,178,102);
       text("ALERT", width/2-100,height*2/3);
     }
    else if(iDistance<=15)
    {  fill(255,0,127);
       text("STOP", width/2-100,height*2/3);
     }
    else 
    {  fill(0,255,128);
       text("SAFE", width/2-100,height*2/3);
    }
    
    if(iDistance < 100 && iDistance != 0) 
    {
        ellipse(x, height/2, 55, 55);
        text(iDistance, width/2+20,height*2/3);
    }
    delay(10);
}

int StringToInt(String string)
{
    int value = 0;
    for(int i = 0; i < string.length(); ++i) {
        if(string.charAt(i) >= '0' && string.charAt(i) <= '9') {
            value *= 10;
            value += (string.charAt(i) - '0');
        }}
     return value;}


void dottedLine(float x1, float y1, float x2, float y2, float steps){
 for(int i=0; i<=steps; i++) {
   float x = lerp(x1, x2, i/steps);
   float y = lerp(y1, y2, i/steps);
   ellipse(x, y,10,10);
 }
}
