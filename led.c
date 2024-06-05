/*
 * led.c
 *
 *  Created on: Jun 5, 2024
 *      Author: dante
 */
//exportar un pin

char* led[8] = { "17", "4", "18", "23", "24", "25", "22", "27" }
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

void writeFile(char* dir_file, char* str){
	FILE * file;
	int flag;

	if((file = fopen(dir_file, "w")) == NULL){
		//error
	}

	if((flag = fputs(str, file)) == -1){
		//error
	}

	fclose(file);
}

int readValue(){
	FILE * file;
	int value;


}


