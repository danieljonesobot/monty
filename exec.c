#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exe(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_opcodes}, {"pall", pall_opcodes},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *opcodes;

	opcodes = strtok(content, " \n\t");
	if (opcodes && opcodes[0] == '#')
		return (0);
	bus.argument = strtok(NULL, " \n\t");
	while (opst[j].opcode && opcodes)
	{
		if (strcmp(opcodes, opst[j].opcode) == 0)
		{	opst[j].f(stack, counter);
			return (0);
		}
		j++;
	}
	if (opcodes && opst[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcodes);
		fclose(file);
		free(content);
		Fstack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
