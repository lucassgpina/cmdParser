#include <cstring.h>

static Command *cmd_table;
void initCmdTable ()

bool readCmd (int *input) {
	
	char args[10][10]; // limitação de 10 argumentos de tamanho 10
 
	// vamos seprarar comando e argumentos por espaço ' '
	char *cmd = strtok(input," ");
 
	char *arg == strtok(NULL," ");
	char arg_index = 0;
	while((arg != NULL) && (arg_index == 0)){
		strcpy(args[arg_index++],arg);
		
		arg = strtok(NULL," ");
	}
}