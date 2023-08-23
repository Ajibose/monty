#include "monty.h"
#include <stdio.h>

/**
 * interpreter - executes opcode
 * @str: name of file
 *
 * Return: void
 */
void interpreter(char *str)
{
	size_t n = 0;
	char *line = NULL, *op;
	stack_t *stack = NULL;
	FILE *stream;
	unsigned int count = 1;

	stream = fopen(str, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", str);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &n, stream)) != -1)
	{
		if (*line == '\n')
		{
			count++;
			continue;
		}
		op = strtok(line, " \t\n");
		global.argument = strtok(NULL, " \t\n");
		if (check_opcode(op) == 1)
			opcode_exec(&stack, op, count);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, str);
			free_dstack_t(stack);
			fclose(stream);
			free(line);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	free_dstack_t(stack);
	fclose(stream);
	free(line);
}

/**
 * main - main function
 * @ac: no of argument
 * @argv: array of arguments
 *
 * Return: o on success
 */
int main(int ac, char *argv[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	interpreter(argv[1]);
	return (0);
}
