#include "monty.h"
#include <stdio.h>
/**
 * pall - Prints all the elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file (unused)
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
