#include "monty.h"

#define MAX 1024
int stack_size = 0;
char buffer[BUF_SIZE * 8];
stack_t *stack = NULL;
/**
 * main - Entry point for the Monty interpreter program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: Returns EXIT_SUCCESS upon successful execution. If there are errors
 * during file handling or instruction execution, appropriate error messages
 * are printed, and the program exits with EXIT_FAILURE.
 */

int main(int argc, char **argv)
{
	ssize_t size;
	char *token, *value;
	int line = 1;
	unsigned int element;

	if (argc != 2)
		printError("USAGE: monty file");
	size = read_textfile(argv[1], MAX);
	if (size == 0)
		printError("Error: Can't open file %s", argv[1]);
	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		value = strtok(NULL, " \t\n");
		if (is_available(token) == -1)
			printError("L%d: unknown instruction %s\n", line, token);
		element = checkIfNum(value, line, token);
		getFunction(token)(&stack, element);
		token = strtok(NULL, " \t\n");
		line++;
	}
	return (EXIT_SUCCESS);
}

