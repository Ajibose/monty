#include "monty.h"

/**
 * sub - adds the top two elements of the stack.
 * @stack: stack head pointer
 * @line_numer: opcode line number in file
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *ptr;

	if (stack_tlen(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too shrt\n", line_number);
		free(global.line);
		free(*stack);
		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	n = ptr->next->n - ptr->n;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	(*stack)->n = n;
	free(ptr);
}
