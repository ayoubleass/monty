#include "monty.h"

#define MAX 1024
int stack_size = 0;
char buffer[BUF_SIZE * 8];
stack_t *stack = NULL;

int main(int argc, char **argv)
{
	ssize_t size;
	char *token, *value;
	int line = 1;
	unsigned int element;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	size = read_textfile(argv[1], MAX);
	if (size == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		value = strtok(NULL, " \t\n");
		if (is_available(token) == -1)
		{
			fprintf(stderr ,"L%d: unknown instruction %s\n", line, token);
			exit(EXIT_FAILURE);
		}
		element = checkIfNum(value, line, token);
		getFunction(token)(&stack, element);
		token = strtok(NULL, " \t\n");
		line++;
	}
	return (EXIT_SUCCESS);
}

