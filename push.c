#include "monty.h"

/**
 * push - adds a new node to the stack
 * @head: the struct
 * @line_number: line number
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int m, i = 0;

	if (data == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (data[i] != '\0')
	{
		if (!isdigit(data[i]))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	m = atoi(data);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = m;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	if ((*head)->prev == NULL)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

