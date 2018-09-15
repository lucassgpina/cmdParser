#ifndef __CMD_PARSER_H_
#define __CMD_PARSER_H_

typedef struct {
	char name[20];
	void(*func)(char args[10][10]);
}Command;

bool readCmd (char *input);
void setCmdTable (Command *table,int table_size);

#endif
