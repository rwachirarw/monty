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

	if (input.data == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (input.data[i] != '\0')
	{
		if (!isdigit(input.data[i]) &&
				(input.data[i] != '-' && input.data[i] != '+'))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	m = atoi(input.data);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = m;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (input.flag)
		add_node_top(head, new_node);
	else
		add_node_end(head, new_node);
}

/**
 * add_node_top - adds node to the top of stack
 * @head: pointer to pointer to the top of the node
 * @node: node to be added
 */
void add_node_top(stack_t **head, stack_t *node)
{
	if (*head == NULL)
	{
		*head = node;
		input.top = *head;
		input.tail = *head;
		return;
	}

	if ((*head)->prev == NULL)
	{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
		input.top = node;
	}
}


/**
 * add_node_end - adds node to the end of the queue
 * @head: pointer to pointer to the top of the node
 * @node: node to be added
 */
void add_node_end(stack_t **head, stack_t *node)
{
	stack_t *tail = input.tail;

	if (*head == NULL)
	{
		*head = node;
		input.top = *head;
		input.tail = *head;
		return;
	}
	if (tail->next == NULL)
	{
		tail->next = node;
		node->prev = tail;
		input.tail = node;
	}
}
