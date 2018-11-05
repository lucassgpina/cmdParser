#include <string.h>
#include <stdlib.h>
#include "cmdParser.h"

static Command *cmd_table;
static size_t t_s;


// 
// gerenciamento de memória
// 
static void* getMemoryBlock (size_t cmd_size){
    static void* mem_block;
    static unsigned int mem_block_size = 0;

    // Só realoca o buffer se o comando for maior que o já alocado
    if( mem_block_size < cmd_size ){
        //cada comando adiciona um \0 a mais. esse valor adiconado a mais é impirico
        /**TODO achar um método melhor de compensar os bytes adicionais*/
        mem_block_size =cmd_size +20;
        void* new_block = realloc(mem_block,mem_block_size);

        if(new_block != NULL)
            mem_block = new_block;
    }else if(cmd_size == 0){
        free(mem_block);
        mem_block = NULL;
    }

    return mem_block;
}

/**
 * @brief Init the command table
 * @param table
 * @param table_size
 */
void setCmdTable (Command *table,size_t table_size){
	
	cmd_table = table;
	t_s = table_size;
}


/**
 * @brief readCmd
 * @param String with a null terminator containing the command + arguments
 * @return
 */
int readCmd (char *input) {
	
    char *argsv[100]; // limitação de 100 argumentos

    // bloco onde será copiado cada um dos argumentos
    char *block = (char *)getMemoryBlock(strlen(input));
 
    // Commando e argumentos são separados por ' '
	char *cmd = strtok(input," ");

    // Se o comando não conter argumentos (logo não contém espaço)
    if(cmd == NULL){
        cmd = input;
    }


    strcpy(block,cmd);


    int cmd_index = 0;
    argsv[cmd_index++] = block; // Já carrega no argv[0] o nome do comando, como padrão.

    // Prepara o block para receber o próximo argumento
    block += strlen(cmd) +1;


	char *arg = strtok(NULL," ");
    while(arg != NULL){
        strcpy(block,arg);
        argsv[cmd_index++] = block;
        block += strlen(arg) +1;
		
		arg = strtok(NULL," ");
	}
	
	int ret = 0;
    for(unsigned int i = 0; i < t_s; i++){
		if(!strcmp(cmd_table[i].name,cmd)){
            ret = cmd_table[i].func(cmd_index,argsv);
		}
	}

    return ret;
}

void closeCmdParser (){
    getMemoryBlock(0);
}
