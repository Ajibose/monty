#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: stack head
 * @line_number: opcode's line number in file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(global.line);
		free_dstack_t(*stack);

		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n < 0 && n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(global.line);
		free_dstack_t(*stack);

		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", n);
}
