#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack head pointer
 * @line_number: opcode line number in file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *ptr;

	if (stack_tlen(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global.line);
		free(*stack);
		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	n = ptr->n + ptr->next->n;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	(*stack)->n = n;
	free(ptr);
}
