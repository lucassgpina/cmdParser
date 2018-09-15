#include <string.h>
#include "cmdParser.h"

static Command *cmd_table;
static int t_s;

void setCmdTable (Command *table,int table_size){
	
	cmd_table = table;
	t_s = table_size;
}

bool readCmd (char *input) {
	
	char args[10][10]; // limitação de 10 argumentos de tamanho 10
 
	// vamos seprarar comando e argumentos por espaço ' '
	char *cmd = strtok(input," ");
 
	char *arg = strtok(NULL," ");
	char arg_index = 0;
	while((arg != NULL) && (arg_index == 0)){
		strcpy(args[arg_index++],arg);
		
		arg = strtok(NULL," ");
	}
	
	for(int i = 0; i < t_s; i++){
		if(!strcmp(cmd_table[i].name,cmd)){
			cmd_table[i].func(args);
			return true;
		}
	}
}
