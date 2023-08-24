#include "monty.h"
#include <stdio.h>


/**
 * open_file - open file
 * @str: file name
 *
 * Return: FILE poietr
 */
FILE *open_file(char *str)
{
	FILE *stream;

	stream = fopen(str, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	return (stream);
}

/**
 * interpreter - executes opcode
 * @str: name of file
 *
 * Return: void
 */
void interpreter(char *str)
{
	size_t n = 0;
	char *op;
	unsigned int count = 1;

	global.stream = open_file(str);
	while ((getline(&global.line, &n, global.stream)) != -1)
	{
		if (*global.line == '\n')
		{
			count++;
			continue;
		}
		op = strtok(global.line, " \t\n");
		if (!op || *op == '#')
		{
			count++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		if (check_opcode(op) == 1)
			opcode_exec(&global.stack, op, count);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, str);
			free_dstack_t(global.stack);
			fclose(global.stream);
			free(global.line);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	free_dstack_t(global.stack);
	fclose(global.stream);
	free(global.line);
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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	interpreter(argv[1]);
	return (0);
}
