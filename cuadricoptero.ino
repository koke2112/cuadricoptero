
#include "cuadricoptero.h"
#include <Servo.h>
#include "motor.h" 
#include "acelerometro.h" 
#include "control.h"

void setup(){ 
  
  pinMode(5,INPUT);//potenciometro de velocidad
  pinMode(0, INPUT);//X del acelerometro
  pinMode(1, INPUT);//Y del acelerometro
  //pinMode(20, INPUT);//Y del acelerometro
  arm();
  arranque();
} 
 
 
void loop() 
{ 
 //poner aqui la lógica del programa.
 //poner llamadas al acelerometro mediante interrupciones o timer
 
	/*if(manual){
		
	}else{
		captura_ac();
	}*/
   int velocidads = map (analogRead(5), 0 , 1023, MIN_SPEED, MAX_SPEED);         //Con ésto yo controlo el motor: hago un mapeado que consta de 1023-(valor del gas al maximo) 0-(Valor de gas al minimo) 40- (VALOR MINIMO QUE NECESITA EL MOTOR PARA MOVERSE) 90-(Valor maximo que le dejo girar al motor.)
   set_speed(1,velocidads);
   set_speed(2,velocidads);
   Serial.print(velocidad[1]*100/90);
   Serial.println("%");
   delay(15);  
  
   
} 
