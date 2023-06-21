#include "monty.h"
/**
 * free_stack - frees the stack
 * @head: head of the stack
 */
void free_stack(stack_t **head)
{
	stack_t *tmp = NULL;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}
