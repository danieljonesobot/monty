#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push_opcodes(stack_t **head, unsigned int counter)
{
    int n;
    
    if (!bus.argument || !is_integer(bus.argument))
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.fil);
        free(bus.cont);
        Fstack(*head);
        exit(EXIT_FAILURE);
    }
    
    n = atoi(bus.argument);
    
    if (bus.li == 0)
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

