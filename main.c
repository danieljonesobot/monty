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
        FILE *fl;
        size_t size = 0;
        ssize_t rdLn = 1;
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
