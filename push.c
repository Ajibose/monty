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
 * @line_number: line number of opcode
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	int arg;
	char *n = global.argument;

	if (check_digit(n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dstack_t(*stack);

		free(global.line);
		fclose(global.stream);
		exit(EXIT_FAILURE);
	}
	arg = atoi(n);
	if (add_dnodeint(stack, arg) == NULL)
	{
		free_dstack_t(*stack);

		free(global.line);
		fclose(global.stream);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_digit - checks if a string is digit
 * @n: string to check
 *
 * Return: 1 on success, 0 otherwise
 */
int check_digit(char *n)
{
	int i = 0;

	if (n[i] == '-')
		i++;

	while (n[i] != '\0')
	{
		if (isdigit(n[i]) == 0)
			return (0);
		i++;
	}

	return (1);
}
