#include "monty.h"

/**
 * parse_div - adds the top two elements of the stack.
 * @stack: stack head pointer
 * @line_number: opcode line number in file
 *
 * Return: void
 */
void parse_div(stack_t **stack, unsigned int line_number)
{
	int n, flag = 0;

	if (stack_tlen(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		flag = 1;
	}

	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		flag = 1;
	}

	if (flag == 1)
	{
		free(global.line);
		free(*stack);
		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = n;
}
