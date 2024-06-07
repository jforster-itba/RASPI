/*
 * led.c
 *
 *  Created on: Jun 5, 2024
 *      Author: dante
 */
//exportar un pin
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void writeFile(char* dir_file, char* str);
char readValue(char* dir_file);

char* led[8] = { "17", "4", "18", "23", "24", "25", "22", "27" };
char* export_led = "/sys/class/gpio/export";
char* value_led[8] = {
	"/sys/class/gpio/gpio17/value",
	"/sys/class/gpio/gpio4/value",
	"/sys/class/gpio/gpio18/value",
	"/sys/class/gpio/gpio23/value",
	"/sys/class/gpio/gpio24/value",
	"/sys/class/gpio/gpio25/value",
	"/sys/class/gpio/gpio22/value",
	"/sys/class/gpio/gpio27/value",
	};

char* direction_led[8] = {
	"/sys/class/gpio/gpio17/direction",
	"/sys/class/gpio/gpio4/direction",
	"/sys/class/gpio/gpio18/direction",
	"/sys/class/gpio/gpio23/direction",
	"/sys/class/gpio/gpio24/direction",
	"/sys/class/gpio/gpio25/direction",
	"/sys/class/gpio/gpio22/direction",
	"/sys/class/gpio/gpio27/direction",
};

int main(void){
	//para exportar writeFile(export_dir , led[n]);
	//para cambiar dir writeFile(dir_led, "out"/"in")
	int i;
	char exit;
	int c;

	// exportamos y ponenmos todos los pines como OUT
	for(i=0;i<7;i++){
			printf("Exportamos el pin %s:", led[i]);
			writeFile(export_led, led[i]);
			printf("Seteamos la direccion del pin %s en OUT: ", led[i]);
			writeFile(direction_led[i], "out");	//seteo direction del led2
	}

	while(exit!=1){

		printf("Indique la instrucción a realizar: \n");

		while( (c = getchar()) != '\n' ){
				//exportamos el led2
			if('0' < c && c < '7'){
					c-='0';
				if(readValue(led[c])==0){
					writeFile(value_led[c], "1");
				}
				else if(readValue(led[c])==1){
					writeFile(value_led[c], "0");
				}
			}

			else{

				switch(c){
					case 't':
					case 'T':
						for(i=0;i<7;i++){
							if(readValue(led[i])==0)
								writeFile(value_led[i], "1");
							else if(readValue(led[i])==1)
								writeFile(value_led[i], "0");
						}

					case 'c':
					case 'C':
						for(i=0;i<7;i++){
							writeFile(value_led[i], "0");
						}
					break;

					case 's':
					case 'S':
						for(i=0;i<7;i++){
							writeFile(value_led[i], "1");
						}
					break;

					case 'q':
					case 'Q':
						printf("programa terminado");

						exit = 1;
					break;

					default:
						printf("Ingrese un caracter valido.");
					break;
				}

			}
		}
	}

	return 0;
}

void writeFile(char* dir_file, char* str){	// dir_file es donde queremos guardar el string str
	FILE * file;
	int flag;

	sleep(1);
	if((file = fopen(dir_file, "w")) == NULL){
		printf("No se pudo abrir el archivo %s", dir_file);
		exit(1);
	}

	sleep(1);
	if((flag = fputs(str, file)) == -1){
		printf("No se pudo escribir el archivo %s", dir_file);
		exit(1);
	}

	sleep(1);
	fclose(file);
}

char readValue(char* dir_file){		// se usa como readValue == '0';
	FILE * file;
	char value;

	sleep(1);

	if((file = fopen(dir_file, "r")) == NULL){
		printf("No se pudo abrir el archivo %s", dir_file);
		exit(1);
	}

	sleep(1);

	if((value = fgetc(file)) == EOF){
		printf("No se pudo escribir el archivo %s", dir_file);
		exit(1);
	}

	sleep(1);

	fclose(file);
	return value;
}


