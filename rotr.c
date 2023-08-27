#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: stack head
 * @line_number - opcode line nymber
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *temp;

	(void) line_number;
	if ((*stack) == NULL || stack == NULL)
		return;

	ptr = *stack;
	temp = *stack;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	if (stack_tlen(ptr) > 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
		temp->prev = ptr;
		temp->next = NULL;
	}
}
