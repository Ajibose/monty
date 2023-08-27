#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#define _GNU_SOURCE
#include <string.h>
#include <ctype.h>
extern char *argument;
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

/**
 * struct all_s - globals to free
 * @argument: opcode argument
 * @stack: head of stack
 * @line: opcode line
 * @stream: file opening
 */
typedef struct all_s
{
	char *argument, *line;
	stack_t *stack;
	FILE *stream;
} all_t;
all_t global;
char **tokenizer(char *str, char *d);
int getlines(char **lineptr, size_t *n, char *pathname, FILE **stream);
void interpreter(char *str);
void opcode_exec(stack_t **stack, char *arg, unsigned int count);
void push(stack_t **stack, unsigned int count);
stack_t *add_dnodeint(stack_t **head, int n);
void pall(stack_t **h, unsigned int count __attribute__((unused)));
int check_opcode(char *str);
void opcode_exec(stack_t **stack, char *str, unsigned int count);
void free_dstack_t(stack_t *head);
void frees(char **str);
void pint(stack_t **stack, unsigned int count);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
size_t stack_tlen(const stack_t *h);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void parse_div(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
int check_digit(char *n);

#endif /* MONTY_H */
