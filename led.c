/*
 * led.c
 *
 *  Created on: Jun 5, 2024
 *      Author: dante
 */
//exportar un pin

char * pin17 = "17";
char * pin4 = "4";
char * pin18 = "18";
char * pin17 = "23";
char * pin17 = "24";
char * pin17 = "25";
char * pin17 = "22";


int export_pin(char* pin){
	FILE * exportar_pin;
	int write_flag;

	exportar_pin = fopen("sys/class/gpio/export","w");
	// chequeo si se cargo el archivo export a exportar_pin

	if(exportar_pin == NULL){
		//error
	}

	write_flag = fputs(pin, exportar_pin);
	if (write_flag == -1){
		// error
	}

}
