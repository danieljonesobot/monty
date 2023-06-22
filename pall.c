#include "monty.h"

/**
 * pall_opcodes - prints the stack
 * @hd: head of the stack
 * @cter: line_num
*/
void pall_opcodes(stack_t **hd, unsigned int cter)
{
    stack_t *h;
    
    (void)cter;
    
    for (h = *hd; h != NULL; h = h->next)
        printf("%d\n", h->n);
}

