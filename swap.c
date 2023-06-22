#include "monty.h"
/**
 * swap_opcodes - swap opcodes
 * @hd: head of stack
 * @cter: line num
 */
void swap_opcodes(stack_t **hd, unsigned int cter)
{
        stack_t *ft, *sd;
        int tp;
        if (*hd == NULL || (*hd)->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", cter);
                fclose(vec.fil);
                free(vec.cont);
                Fstack(*hd);
                exit(EXIT_FAILURE);
        }

        ft = *hd;
        sd = (*hd)->next;
        tp = ft->n;
        ft->n = sd->n;
        sd->n = tp;
}
