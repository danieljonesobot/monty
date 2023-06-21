#include "monty.h"

/**
 * push_opcodes - adds and new node
 * @head: head of stack
 * @counter:number
 * Return: void 
*/
void push_opcodes(stack_t **head, unsigned int cter)
{
    int n;
    
    if (!vec.argument || !is_integer(vec.argument))
    {
        fprintf(stderr, "L%d: usage: push integer\n", cter);
        fclose(vec.fil);
        free(vec.cont);
        Fstack(*head);
        exit(EXIT_FAILURE);
    }
    
    n = atoi(vec.argument);
    
    if (vec.li == 0)
        node_add(head, n);
    else
        queue_add(head, n);
}

/**
 * is_integer - check if a string represents an integer
 * @str: string to check
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    
    if (*str == '\0')
        return 0;
    
    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    
    return 1;
}

