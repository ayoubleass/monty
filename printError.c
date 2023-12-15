#include "monty.h"
#include <stdarg.h>

/**
 * printError - Print an error message with
 * formatted arguments to stderr and exit.
 * @message: The error message string with
 * optional format specifiers (%s, %d).
 * It can include a combination of regular characters and format specifiers.
 * Supported format specifiers: %s (string), %d (integer).
 * @...: Additional arguments
 * corresponding to the format specifiers in the message.
 *       The number and types of arguments should match the format specifiers.
 */
void printError(char *message, ...)
{
	va_list args;

	va_start(args, message);
	while (*message != '\0')
	{
		if (*message == '%' && (*(message + 1) == 's'
		|| *(message + 1) == 'd'))
		{
			if (*(message + 1) == 's')
			{
				fprintf(stderr, "%s", va_arg(args, char *));
			} else if (*(message + 1) == 'd')
			{
				fprintf(stderr, "%d", va_arg(args, int));
			}
			message += 2;
		}
		else
		{
			fprintf(stderr, "%c", *message);
			message++;
		}
	}

	va_end(args);
	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}
