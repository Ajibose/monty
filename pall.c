#include "monty.h"

/**
 * pall - prints the element of a stack
 * @h: pointer to the head of the stack
 * @count: opcode line number
 *
 * Return: void
 */
void pall(stack_t **h, unsigned int count __attribute__((unused)))
{
	stack_t *ptr = *h;

	if (*h != NULL)
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
}
