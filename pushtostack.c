#include  "monty.h"
/**
 * push - Pushes a new node onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (stack_size == LIMIT - 1)
		printError("Stack overflow");
	if (new_node == NULL)
		printError("Error: malloc failed");
	new_node->n = line_number;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
	stack_size++;
}
