#include "monty.h"

/**
 * frees - frees up a 2D array
 * @str: The array to free
 *
 * Return: none
 */
void frees(char **str)
{
	int i = 0;

	if (str != NULL)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

/**
 * free_dstack_t - Frees a double linked list stack
 * @head: pointer to the head of stack
 *
 * Return: void
 *
 */
void free_dstack_t(stack_t *head)
{
	stack_t *ptr;

	if (head != NULL)
		while (head != NULL)
		{
			ptr = head;
			head = head->next;
			free(ptr);
		}
}
