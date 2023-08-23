#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: head pointer
 * @count: opcode line number
 *
 */
void pint(stack_t **stack, unsigned int count)
{
	int top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", count);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->n;
	printf("%d\n", top);
}
