#ifndef __CMD_PARSER_H_
#define __CMD_PARSER_H_

#include <cstdint>

typedef struct {
	char name[20];
        void(*func)(int argc, char *argv[]);
}Command;

int_fast8_t readCmd (char *input);
void setCmdTable (Command *table,size_t table_size);

#endif
