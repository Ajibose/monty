#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: stack head
 * @line_number: opcode line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(global.line);
		free_dstack_t(*stack);

		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	n = (*stack)->n;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(ptr);
}
