#include "monty.h"
/**
 * pint_opcode - printing the top of the stack
 * @hd: head of the stack
 * @cter: line_number
 * Return: void
*/
void pint_opcode(stack_t **hd, unsigned int cter)
{
	if (*hd == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cter);
		fclose(vec.fil);
		free(vec.cont);
		Fstack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*hd)->n);
}
