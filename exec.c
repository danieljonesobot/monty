#include "monty.h"
/**
* exe - runst opcodes
* @stk: head of stack
* @cter: line count
* @fe: pointer
* @ctent: contents of line
* Return: void
*/
int exe(char *ctent, stack_t **stk, unsigned int cter, FILE *fe)
{
	instruction_t op_S[] = {
				{"push", push_opcodes}, {"pall", pall_opcodes},{"pint", pint_opcode},
				{"pop",pop_opcodes},{"swap",swap_opcodes},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *opcodes;

	opcodes = strtok(ctent, " \n\t");
	if (opcodes && opcodes[0] == '#')
		return (0);
	vec.argument = strtok(NULL, " \n\t");
	while (op_S[j].opcode && opcodes)
	{
		if (strcmp(opcodes, op_S[j].opcode) == 0)
		{	op_S[j].f(stk, cter);
			return (0);
		}
		j++;
	}
	if (opcodes && op_S[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", cter, opcodes);
		fclose(fe);
		free(ctent);
		Fstack(*stk);
		exit(EXIT_FAILURE); }
	return (1);
}
