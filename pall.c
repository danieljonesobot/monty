#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: not used
 * Return: no return
*/
void pall_opcodes(stack_t **head, unsigned int counter)
{
    stack_t *h;
    
    (void)counter;
    
    for (h = *head; h != NULL; h = h->next)
        printf("%d\n", h->n);
}

