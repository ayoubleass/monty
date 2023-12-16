#include "monty.h"
#include <stdio.h>


/**
 * pint - Print the value at the top of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: Line number in
 * the Monty bytecode file (unused in this function)
 */


void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *cpy = *stack;

	if (cpy == NULL)
		printError("L%d: can't pint, stack empty", line_number);
	printf("%d\n", cpy->n);
}
