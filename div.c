#include "monty.h"

/**
 * div - adds the top two elements of the stack.
 * @stack: stack head pointer
 * @line_number: opcode line number in file
 *
 * Return: void
 */
void div(stack_t **stack, unsigned int line_number)
{
	int n, flag = 0;
	stack_t *ptr;

	if (stack_tlen(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		flag = 1
	}

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		flag = 1;
	}

	if (flag)
	{
		free(global.line);
		free(*stack);
		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	n = ptr->next->n / ptr->n;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	(*stack)->n = n;
	free(ptr);
}
