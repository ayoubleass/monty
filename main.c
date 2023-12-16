#include "monty.h"
#include <stdio.h>

#define MAX 1024
int stack_size = 0;
char *buffer;
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
	int line = 1;
	FILE *fd;

	if (argc != 2)
		printError("USAGE: monty file");
	fd = fopen(argv[1], "r");
	if (!fd)
		printError("Error: Can't open file %s", argv[1]);
	buffer = malloc(MAX * sizeof(char));
	while (fgets(buffer, MAX, fd) != NULL)
	{
		parse_then_execute(&stack, line, buffer);
		line++;
	}
	free(buffer);
	fclose(fd);
	return (EXIT_SUCCESS);
}
