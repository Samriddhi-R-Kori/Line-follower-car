#include<evive.h>

#define motor1_dir1 28
#define motor1_dir2 29
#define motor2_dir1 30
#define motor2_dir2 31
#define motor1_pwm 44
#define motor2_pwm 45
#define ir_left 2
#define ir_right 3

unsigned int ir_left_sensor =0;
unsigned int ir_right_sensor = 0;

void setup()
    {
        // put your setup code here, to run once:

        Serial.begin(9600);

        for(unsigned int i =28;i<32;i++)
           {
              pinMode(i,OUTPUT);
           }
        pinMode(motor1_pwm,OUTPUT);
        pinMode(motor2_pwm,OUTPUT);

        pinMode(ir_left,INPUT);
        pinMode(ir_right,INPUT);

        tft_init(INITR_GREENTAB);
        tft.setRotation(1);
        tft.fillScreen(ST7735_BLACK);

        tft.setCursor(25,10);
        tft.setTextSize(2);
        tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
        tft.print("STEMpedia");

        tft.setCursor(20,35);
        tft.setTextSize(1);
        tft.setTextColor(ST7735_GREEN,ST7735_BLACK);
        tft.print("LINE FOLLOWER ROBOT ");

        tft.setTextColor(ST7735_GREEN,ST7735_BLACK);
        tft.setCursor(0,105);
        tft.setTextSize(1.8);
        tft.print("FOR MORE INFORMATION VISIT");
        tft.setCursor(30,115);
        tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
        tft.print("thestempedia.com");
  

}

void loop() 
{
  // put your main code here, to run repeatedly:

  ir_left_sensor = digitalRead(ir_left);
  ir_right_sensor = digitalRead(ir_right);
  analogWrite(motor1_pwm,int(analogRead(A9)/4.0));
  analogWrite(motor2_pwm,int(analogRead(A9)/4.0));
  
  if(ir_left_sensor ==HIGH)
  {
      tft.fillRoundRect(40,60, 30, 30, 5, ST7735_GREEN);
  }
  else
  {
       tft.fillRoundRect(40,60, 30, 30, 5, ST7735_BLUE);
  }
  if(ir_right_sensor ==HIGH)
  {
        tft.fillRoundRect(90,60, 30, 30, 5, ST7735_GREEN);
  }
  else
  {
        tft.fillRoundRect(90,60, 30, 30, 5, ST7735_BLUE);
  }

  if((ir_left_sensor ==HIGH && ir_right_sensor==HIGH))
  {
    Serial.println("Fwd");
    forward();
  }
  if( ir_left_sensor ==HIGH && ir_right_sensor==LOW)
  {
    Serial.println("left");
    left();
  }
  if( ir_left_sensor ==LOW && ir_right_sensor==HIGH)
  {
    Serial.println("right");
    right();
  }

  if(digitalRead(40)==HIGH)
  {
    Serial.println("stop");
    Stop();
  }
  delay(analogRead(A10));
  

}

void forward()
{
  digitalWrite(motor1_dir1,HIGH);
  digitalWrite(motor1_dir2,HIGH);
  digitalWrite(motor2_dir1,HIGH);
  digitalWrite(motor2_dir2,LOW);
}
void backward()
{
  digitalWrite(motor1_dir1,LOW);
  digitalWrite(motor1_dir2,HIGH);
  digitalWrite(motor2_dir1,LOW);
  digitalWrite(motor2_dir2,HIGH);
}
void left()
{
  digitalWrite(motor1_dir1,HIGH);
  digitalWrite(motor1_dir2,LOW);
  digitalWrite(motor2_dir1,LOW);
  digitalWrite(motor2_dir2,LOW);
}
void right()
{
  digitalWrite(motor1_dir1,LOW);
  digitalWrite(motor1_dir2,LOW);
  digitalWrite(motor2_dir1,HIGH);
  digitalWrite(motor2_dir2,LOW);
}
void Stop()
{
  digitalWrite(motor1_dir1,LOW);
  digitalWrite(motor1_dir2,LOW);
  digitalWrite(motor2_dir1,LOW);
  digitalWrite(motor2_dir2,LOW);
}




