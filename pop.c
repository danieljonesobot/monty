#include "monty.h"
/**
 * pop_opcodes - pop operation on the stack
 * @hd: head of stack
 * cter: line number
 */

void pop_opcodes(stack_t **hd, unsigned int cter)
{
        if (*hd == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", cter);
                fclose(vec.fil);
                free(vec.cont);
                Fstack(*hd);
                exit(EXIT_FAILURE);
        }
        else
        {
                stack_t *temp = *hd;
                *hd = (*hd)->next;
                free(temp);
        }
}
