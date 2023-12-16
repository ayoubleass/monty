#ifndef STACK_QUEUE
#define STACK_QUEUE
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define LIMIT 100

#define BUF_SIZE 1024
/*extern char *buffer;*/
extern unsigned int element;
extern int stack_size;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

size_t _getline(char **lineptr, size_t *n, FILE *stream);
void printError(char *message, ...);
ssize_t read_textfile(const char *filename, size_t letters);
int is_available(char *action);
unsigned int checkIfNum(char *value, int line, char  *action);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void (*getFunction(char *choice))(stack_t **, unsigned int);
void parse_then_execute(stack_t **stack, unsigned int line, char *buffer);
int singleParam(char *param);
void pint(stack_t **stack, unsigned int line_number);
#endif
