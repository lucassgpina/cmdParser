#include <stdio.h>
#include "cmdParser.h"


int hello (int argc, char *argv[]){
    printf("hi there!\n");
    printf("here is the arguments:\n");
    for(int i = 0; i < argc;++i){
        printf("%s\n",argv[i]);
    }
    return 0;
}


Command cmd_table [] = {
    {"hello",hello}
};


int main(int argc, char *argv[])
{
    setCmdTable(cmd_table,sizeof(cmd_table)/sizeof(cmd_table[0]));
    printf("cmdparser\n");

    char cmd_in[256];

    printf("%s","enter command: ");
    scanf("%[^\n]s",cmd_in);

    readCmd(cmd_in);


    return 0;
}
