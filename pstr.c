#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void) line_number;
	while (ptr != NULL)
	{
		if (ptr->n == 0 || isascii(ptr->n) == 0)
			break;
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}
