#include "monty.h"

#define MAX 1024
char buffer[BUF_SIZE * 8];
unsigned int element;
stack_t *stack = NULL;


int main(int argc, char **argv)
{
	ssize_t size;
	char *token, *value;
	int line = 1;

	if (argc != 2)
		exit(EXIT_FAILURE);
	size = read_textfile(argv[1], MAX);
	if (size == -1)
	{
		printf("Error readiing the file");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " \t\n");

	while (token != NULL)
	{
		value = strtok(NULL, " \t\n");
		if (is_available(token) == -1)
		{
			printf("L%d: unknown instruction %s\n", line, token);
			exit(EXIT_FAILURE);
		}
		checkIfNum(value, line);
		getFunction(token)(&stack, element);
		token = strtok(NULL, " \t\n");
		line++;
	}
	return (EXIT_SUCCESS);
}

