#include "monty.h"
/**
 * queue_add - add new node 
 * @n: new
 * @head: head 
 * Return: void 
*/
void queue_add(stack_t **head, int n)
{
    stack_t *nde = malloc(sizeof(stack_t));
    
    if (nde == NULL)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
    
    nde->n = n;
    nde->next = NULL;
    
    if (*head == NULL)
    {
        nde->prev = NULL;
        *head = nde;
    }
    else
    {
        stack_t *tl = *head;
        
        while (tl->next != NULL)
            tl = tl->next;
        
        tl->next = nde;
        nde->prev = tl;
    }
}
/**
 * node_add - add node
 * @head: head 
 * @n: new value
 * Return: void
*/
void node_add(stack_t **head, int n)
{
	stack_t *nde = malloc(sizeof(stack_t));

	if (nde == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
	nde->n = n;
	nde->prev = NULL;
	if (*head != NULL)
		(*head)->prev = nde;
	nde->next = *head;
	*head = nde;
}

/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void Fstack(stack_t *hd)
{
    stack_t *cur = hd;

    while (cur != NULL)
    {
        stack_t *next = cur->next;
        free(cur);
        cur = next;
    }
}


ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i = 0;
	char *new_ptr;
    
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			new_ptr = (char *)realloc(*lineptr, *n);
			if (new_ptr == NULL)
			{
				return (-1);
			}
			*lineptr = new_ptr;
		}
		(*lineptr)[i++] = (char)c;
		if (c == '\n')
		{
			break;
		}
	}
	if (i == 0)
	{
		return (-1);
	}
	(*lineptr)[i] = '\0';
	return (ssize_t)i;
}


