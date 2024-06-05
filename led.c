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

/*
void exportarPin(char* pin){
	FILE * exportar;
	int flag;

	exportar = fopen("sys/class/gpio/export","w");
	// chequeo si se cargo el archivo export a exportar_pin

	if(exportar == NULL){
		//error
	}

	flag = fputs(pin, exportar);
	if (flag == -1){
		// error
	}

	fclose(exportar);
}
*/

void writeFile(char* dir_file, char* str){	// dir_file es donde queremos guardar el string str
	FILE * file;
	int flag;

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

int main(void){
	//para exportar writeFile(export_dir , led[n]);
	//para cambiar dir writeFile(dir_led, "out"/"in")
	char c;
	while( (c = getchar()) != 'q' && (c != 'Q') ){
		printf("Exportamos el pin %s:", led[2]);
		writeFile(export_led, led[2]);	//exportamos el led2

		printf("\n");

		printf("Seteamos la direccion del pin %s en OUT: ", led[2]);
		writeFile(direction_led[2], "out");	//seteo direction del led2

		printf("\n");

		char v = readValue(value_led[2]);
		printf("El valor actual del pin %s es: %c", led[2], v);

		printf("\n");

		printf("Seteamos el valor del pin %s en 1: ", led[2]);
		writeFile(value_led[2], "1");	//seteo value del led2

		printf("\n");
	}

	return 0;
}


