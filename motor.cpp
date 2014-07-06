// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

#include "cuadricoptero.h"
#include <Servo.h> 
 
Servo motor1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo motor2;              
Servo motor3;
Servo motor4;


int pos = 0;    // variable to store the servo position 
int velocidad[4];//variables para guardar la velocidad de los motores

void set_speed(int mot, int sp){
	switch (mot){
		case 1:
			motor1.write(sp); 
			  
			break;
		case 2:
			motor2.write(sp); 
			
			break;
		case 3:
			motor3.write(sp); 
			   
			break;
		case 4:
			motor4.write(sp); 
			
			break;
	}
	velocidad[mot]=sp;

}     
  

   

void arm(){  
	
  motor1.attach(9); 
  motor2.attach(10);                                                                // Funcion del armado del ESC
  motor1.write(0);
  motor2.write(0);
  delay(100);
  motor1.write(20);
  motor2.write(20);
  delay(100);

}
