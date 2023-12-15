#include "monty.h"
/**
 * read_textfile - Reads a text file and prints it to stdout
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: Number of letters read and printed, or 0 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t size;

	if (!filename || !letters)
	return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	size = read(fd, &buffer[0], letters);
	if (size == -1)
		return (0);
	close(fd);
	return (size);
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
			{NULL, NULL}
	};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(choice, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * checkIfNum - Checks if a string represents a valid number
 * @value: String to check
 *
 * Return: 0 if the string is a valid number, otherwise exit with failure
 */
int checkIfNum(char *value)
{
	if (value)
	{
		element = atoi(value ? value : NULL);
		if (element == 0)
		{
			printf("elemeent");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
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
	return (-1);
}
