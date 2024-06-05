/*
 * led.c
 *
 *  Created on: Jun 5, 2024
 *      Author: dante
 */
//exportar un pin
int export_pin(){
	FILE * exportar_pin;
	int write_flag;

	exportar_pin = fopen("sys/class/gpio/export","w");
	// chequeo si se cargo el archivo export a exportar_pin
	if(exportar_pin == NULL){
		//error
	}

	write_flag = fputs(, exportar_pin);
	if (write_flag == -1){
		// error
	}

}
