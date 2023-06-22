#include "monty.h"
/**
 * add_opcodes - add opcodes
 * @hd: head of stack
 * @cter: line_num
 */
void add_opcodes(stack_t **hd, unsigned int cter)
{
        stack_t *ft;

        if (*hd == NULL || (*hd)->next == NULL)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", cter);
                fclose(vec.fil);
                free(vec.fil);
                Fstack(*hd);
                exit(EXIT_FAILURE);
        }

        ft = *hd;
        ft->next->n += ft->n;
        *hd = ft->next;
        free(ft);
}
