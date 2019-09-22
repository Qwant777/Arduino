#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;
int van1=90;
int van2=90;
int van3=90;

int val; //переменная в которую будем записывать команды по bluetooth

void setup()
{
   myservo.attach(7);
   myservo1.attach(6);
   myservo2.attach(4);
Serial.begin(9600); // запускаем работу с портом
pinMode(13, OUTPUT); //говорим, что порт Reley1, т.е. порт D7 явлюяется портом вывода
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
Serial.println("Press 1 to ON or 0 to OFF");
}
void loop()
{
if (Serial.available()) //если из последовательного интерфейса что пришло, значит…
{
val = Serial.read(); // заносим в переменную val, то что пришло в порт

if (val == 'w') 
{
digitalWrite(13, HIGH);
digitalWrite(10, HIGH);
Serial.println("vpered");
//delay(100);
//digitalWrite(13, LOW);
//digitalWrite(10, LOW);
}
if (val == 's') 
{
digitalWrite(12, HIGH);
digitalWrite(11, HIGH);
Serial.println("nazad");
//delay(100);
//digitalWrite(12, LOW);
//digitalWrite(11, LOW);
}
if (val == 'a') 
{
digitalWrite(13, HIGH);
digitalWrite(11, HIGH);
Serial.println("povorot l");
//delay(100);
//digitalWrite(13, LOW);
//digitalWrite(11, LOW);
}
if (val == 'd') 
{
digitalWrite(12, HIGH);
digitalWrite(10, HIGH);
Serial.println("povorotr");
//delay(100);
//digitalWrite(13, LOW);
//digitalWrite(11, LOW);
}

if (val == 'k') 
{

Serial.println("servoup");
van1 = van1 + 10;
if (van1 > 180) van1 = 180;    //ограничим угол сервы 0..180
if (van1 < 0) van1 = 0;


myservo.write(van1);
delay(300);




}


if (val == 'i') 
{

Serial.println("servodown");

van1 = van1 - 10;
if (van1 > 180) van1 = 180;    //ограничим угол сервы 0..180
if (van1 < 0) van1 = 0;


myservo.write(van1);
delay(300);
}

if (val == 'j') 
{

Serial.println("servoleft");
van2 = van2 + 10;
if (van2 > 180) van2 = 180;    //ограничим угол сервы 0..180
if (van2 < 0) van2 = 0;


myservo1.write(van2);
delay(300);

}
if (val == 'l') 
{

Serial.println("servoright");

van2 = van2 - 10;
if (van2 > 180) van2 = 180;    //ограничим угол сервы 0..180
if (van2 < 0) van2 = 0;


myservo1.write(van2);
delay(300);
}

if (val == 'n') 
{

Serial.println("servoup1");

van3 = van3 + 10;
if (van3 > 180) van3 = 180;    //ограничим угол сервы 0..180
if (van3 < 0) van3 = 0;


myservo2.write(van3);
delay(300);

}
if (val == 'm') 
{

Serial.println("servodown1");
van3 = van3 - 10;
if (van3 > 180) van3 = 180;    //ограничим угол сервы 0..180
if (van3 < 0) van3 = 0;


myservo2.write(van3);
delay(300);
}



if ( val == 'p') // если пришел символ "0" выключаем реле
{
digitalWrite(13, LOW);
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
Serial.println("tormoz");
}

}
}
