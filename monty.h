#ifndef MONTY_H
#define MONTY_H
#include <sys/types.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct ch_s - var 
 * @argument: val
 * @fil: pointer
 * @cont: l c
 * @li: flag change
 * Description: takes the values into the program
 */
typedef struct ch_s
{
	char *argument;
	FILE *fil;
	char *cont;
	int li;
}  ch_t;
extern ch_t vec;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_opcodes(stack_t **head, unsigned int counter);
int is_integer(const char *str);
void pall_opcodes(stack_t **head, unsigned int counter);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void Fstack(stack_t *hd);
void node_add(stack_t **head, int n);
void queue_add(stack_t **head, int n);
int exe(char *content, stack_t **stack, unsigned int counter, FILE *file);
void pint_opcode(stack_t **hd, unsigned int cter);
void pop_opcodes(stack_t **hd, unsigned int cter);
void swap_opcodes(stack_t **hd, unsigned int cter);
#endif 
