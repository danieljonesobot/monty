#include "monty.h"
ch_t vec = {NULL, NULL, NULL, 0};
/**
* main - monty entry point
* @argc: arg counter
* @argv: args
* Return: 0 
*/

int main(int argc, char *argv[])
{
        char *cote;
        size_t size = (1-1);
        FILE *fl;
        ssize_t rdLn = 1;
        unsigned int count = (2-2);
        stack_t *stk = NULL;

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
        while (rdLn > 0)
        {
                cote = NULL;
                rdLn = _getline(&cote, &size, fl);
                vec.cont = cote;
                count++;
                if (rdLn > 0)
                {
                        exe(cote, &stk, count, fl);
                }
                free(cote);
        }
        Fstack(stk);
        fclose(fl);
return (0);
}
