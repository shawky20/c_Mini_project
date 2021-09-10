/*
 ============================================================================
 Name        : project.c
 Author      : shawky Abo el-ela
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define WITH_ENGINE_temperature_CONTROLLER 1

typedef enum{
	OFF =0,
	ON =1
}bool;

// this variables are global to be used in the functions
int v_speed=60; // vehicle speed initial value =60
bool engine_temperature_controller = OFF;
bool AC = OFF;


void getTraffic_light(char c3);
void getRoomtemperature(int *temperature);
void getEnginetemperature(int *eng_temperature);

int main(void) {

	printf("Enter what you want to do:\na/Turn on the vehicle engine\nb/Turn off the vehicle engine\nc/Quit the system\n");

	char c,c2,c3;// c to define Engine state, c2 to choose from the menu set , c3 to enter the traffic light
	int temperature=25; // room temperature
#if WITH_ENGINE_temperature_CONTROLLER
	int eng_temperature = 90 ; // engine temperature
#endif


	fflush(stdout);
	scanf("%c",&c);

    if (c == 'b'){

    	do {
    		printf("the system is off\n");
    		printf("Enter what you want to do:\na/Turn on the vehicle engine\nb/Turn off the vehicle engine\nc/Quit the system\n");
    		fflush(stdout);
    		scanf(" %c",&c);


    	}while(c == 'b');
    }
    if (c == 'c'){
    	printf("Quit the system");
       	return 0;
       }

    if (c == 'a') {
    	printf("the system is ON\n");
       do {
    	    	printf("Sensors set menu:\na/Turn off the engine\nb/Set the traffic light color.\nc/Set the room temperature (temperature Sensor)\n");
#if WITH_ENGINE_temperature_CONTROLLER
    	    	printf("d/Set the engine temperature (Engine temperature Sensor)\n");
#endif
    	    	fflush(stdout);
    	    	scanf(" %c",&c2);



                if(c2 =='b'){
                	printf("what is the traffic light data 'R' or 'G' or 'O' ?\n");
                	fflush(stdout);
                	scanf(" %c",&c3);

                	getTraffic_light(c3);
                }


                if(c2 == 'c'){
                	printf("what is the room temperature ?\n");
                	fflush(stdout);
                	scanf("%d",&temperature);

                	getRoomtemperature(&temperature); //pass by address
                }

#if WITH_ENGINE_temperature_CONTROLLER
                if (c2 == 'd'){
                	printf("what is engine temperature data ?\n");
                	fflush(stdout);
                	scanf("%d",&eng_temperature);

                	getEnginetemperature(&eng_temperature); //pass by address
                }
#endif

                if (v_speed == 30){
                	AC = ON;
                	temperature = temperature *( (5/4)+1);

#if WITH_ENGINE_temperature_CONTROLLER
                	engine_temperature_controller = ON;
                	eng_temperature = eng_temperature * ((5/4)+1);
#endif
                }


                if (c2 != 'a'){ // will be displayed at any case except if it was OFF
                	c == 'a'?printf("\nEngine State: ON\n"):printf("\nEngine State: OFF\n");
                	AC == ON?printf("AC: ON\n"):printf("AC: OFF\n");
                	printf("Vehicle Speed: %d m/s\n",v_speed);
                	printf("Room temperature: %d C\n",temperature);
#if !(WITH_ENGINE_temperature_CONTROLLER)
    	    	    printf("\n");
#endif

#if WITH_ENGINE_temperature_CONTROLLER
                	engine_temperature_controller==1?printf("Engine temperature controller state : ON\n"):printf("Engine temperature controller State: OFF\n");
                	printf("Engine temperature: %d C\n\n",eng_temperature);
#endif
                }

    	        if (c2 == 'a'){

    	        	do {
    	        		printf("the system is off\n");
    	        		printf("Enter what you want to do:\na/Turn on the vehicle engine\nb/Turn off the vehicle engine\nc/Quit the system\n");
    	        		fflush(stdout);
    	        		scanf("%c",&c);
    	        		c=getchar();

    	        	}while(c == 'b');
    	        }
    	        if(c == 'c'){
    	        	printf("Quit the system");
    	               	return 0;
    	               }

       } while( c == 'a');



    }

	return EXIT_SUCCESS;
}



void getTraffic_light(char c3){
			if(c3 == 'G' || c3 == 'g')
				v_speed = 100;
			else if(c3 == 'O' || c3 == 'o' )
				v_speed =30;
			else
				v_speed = 0;
}

void getRoomtemperature(int *temperature){
		if (*temperature < 10 || *temperature >30){
				AC = ON;
				*temperature = 20;
			}
			else {
				AC = OFF;
			}
}

void getEnginetemperature(int *eng_temperature){
	if (*eng_temperature < 100 || *eng_temperature > 150 ){
		engine_temperature_controller = ON;
		*eng_temperature = 125;
	}
	else
		engine_temperature_controller = OFF;
}
