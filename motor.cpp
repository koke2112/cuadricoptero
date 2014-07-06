// 
// by Jorge Sanchez  
// jorge_chem_89@hotmail.com

#include "cuadricoptero.h"
#include <Servo.h> 
 
Servo motor1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo motor2;              
Servo motor3;
Servo motor4;
Servo motor[4];

int pos = 0;    // variable to store the servo position 
int velocidad[4];//variables para guardar la velocidad de los motores

void set_speed(int mot, int sp){
	int aux=mot-1;
	/*switch (mot){
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
	}*/
	motor[mot].write(sp);
	velocidad[mot]=sp;

}     
  

   

void arm(){  
	int pin=8;
	for(int i=0;i<sizeof(motor);i++){
		motor[i].attach(pin+i);
		motor[i].write(0);
	}
  delay(100);
  for(int i=0;i<sizeof(motor);i++){
		motor[i].write(20);
	}
  delay(100);

}
