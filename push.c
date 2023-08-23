#include "monty.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a linked list
 * @head: double pointer to the head node
 * @n: the new node data
 *
 * Return: address of the new node
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(temp);
		return (NULL);
	}

	temp->n = n;
	temp->next = *head;
	temp->prev = NULL;

	if (*head != NULL)
		(*head)->prev = temp;

	*head = temp;
	return (temp);
}


/**
 * push - push an elemnt to the stack
 * @stack: linked list stack
 * @count: line number of opcode
 *
 */
void push(stack_t **stack, unsigned int count)
{
	int arg;
	char *n = global.argument;

	if (isdigit(*n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	arg = atoi(n);
	if (add_dnodeint(stack, arg) == NULL)
		exit(EXIT_FAILURE);
}
