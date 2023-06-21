#include "monty.h"
ch_t vec = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty fl location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
        char *cote;
        FILE *fl;
        size_t size = 0;
        ssize_t read_line = 1;
        stack_t *stk = NULL;
        unsigned int count = 0;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        fl = fopen(argv[1], "r");
        vec.fil = fl;
        if(!fl)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        while (read_line > 0)
        {
                cote = NULL;
                read_line = _getline(&cote, &size, fl);
                vec.cont = cote;
                count++;
                if (read_line > 0)
                {
                        exe(cote, &stk, count, fl);
                }
                free(cote);
        }
        Fstack(stk);
        fclose(fl);
return (0);
}
