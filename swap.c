#include "monty.h"

/**
 * stack_tlen - count the number of nodes in a linked list
 * @h: pointer to the head node
 *
 * Return: size of the linked list
 */
size_t stack_tlen(const stack_t *h)
{
	size_t i = 0;
	const stack_t *ptr = h;

	if (h != NULL)
		while (ptr != NULL)
		{
			i++;
			ptr = ptr->next;
		}

	return (i);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack head
 * @line_number: opcode's line number in file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack_tlen(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(global.line);
		free_dstack_t(*stack);

		fclose(global.stream);
		exit(EXIT_FAILURE);
	}

	/**
	 * (*stack)->prev = (*stack)->next;
	 * (*stack)->next = (*stack)->next->next;
	 * (*stack)->next->next = *stack;
	 * *stack = (*stack)->prev;
	 * (*stack)->next->next->prev = (*stack)->next;
	 * (*stack)->prev = NULL;
	 */
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
