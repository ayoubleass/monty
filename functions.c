#include "monty.h"
#include <stdio.h>


/**
 * parse_then_execute - Tokenizes and executes Monty bytecode instructions
 * @stack: A pointer to the top of the stack
 * @line: Current line number in the Monty bytecode file
 * @buffer: A string containing Monty bytecode instructions
 */

void parse_then_execute(stack_t **stack, int line, char *buffer)
{
	char *token, *value;
	unsigned int element;

	token = strtok(buffer, " \t\n");

	while (token != NULL)
	{
		value = strtok(NULL, " \t\n");
		if (is_available(token) == -1)
			printError("L%d: unknown instruction %s\n", line, token);
		element = checkIfNum(value, line, token);
		getFunction(token)(stack, element);
		token = strtok(NULL, " \t\n");
	}
}
/**
 * getFunction - Returns a function pointer based on the given choice
 * @choice: Opcode to match with available functions
 *
 * Return: Pointer to the matched function, or NULL if not found
 */

void (*getFunction(char *choice))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{NULL, NULL}
	};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(choice, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
 * checkIfNum - Checks if a string represents a valid number
 * @value: String to check
 * @line: file line
 * @action: stack operation
 * Return: 0 if the string is a valid number, otherwise exit with failure
 */
unsigned int checkIfNum(char *value, int line, char  *action)
{
	unsigned int element = 0;

	if (value && action && singleParam(action) == -1)
	{
		element = atoi(value ? value : NULL);
		if (element == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	else if (!value && singleParam(action) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	return (element);
}

/**
 * is_available - Checks if a given action is available
 * @action: Action to check
 *
 * Return: 1 if the action is available, -1 otherwise
 */
int is_available(char *action)
{
	if (strcmp(action, "push") == 0 || strcmp(action, "pop") == 0 ||
	strcmp(action, "pall") == 0) {
		return (1);
	}
	if (strcmp(action, "pint") == 0)
		return (1);
	return (-1);
}

/**
 * singleParam - Check if the given parameter
 * corresponds to a single-argument instruction
 * @param: The parameter to check
 * Return:
 * Returns 1 if the parameter corresponds to a known
 * single-argument instruction, -1 otherwise.
 */

int singleParam(char *param)
{
	if (strcmp(param, "pall") == 0)
		return (1);
	if (strcmp(param, "pint") == 0)
		return (1);
	return (-1);
}
