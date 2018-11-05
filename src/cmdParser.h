#ifndef __CMD_PARSER_H_
#define __CMD_PARSER_H_

#include <stdint.h>

typedef struct {
	char name[20];
	int(*func)(int argc, char *argv[]);
}Command;

int readCmd (char *input);
void setCmdTable (Command *table,size_t table_size);

#endif
