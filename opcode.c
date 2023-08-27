#include "monty.h"

const instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", parse_div},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{NULL, NULL}
};

/**
 * check_opcode - check if the opcode given is correct
 * @str: opcode given
 *
 * Return: 1 on success. 0 otherwise
 */
int check_opcode(char *str)
{
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, str) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * opcode_exec - execute opcode
 * @stack: double pointer to stack head
 * @str: opcode given
 * @count: opcode line number
 *
 * Return: void
 */
void opcode_exec(stack_t **stack, char *str, unsigned int count)
{
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, str) == 0)
		{
			opcodes[i].f(stack, count);
			return;
		}
		i++;
	}
}
