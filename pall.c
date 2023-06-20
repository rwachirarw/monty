#include "monty.h"
/**
 * pall - prints data in the stack
 * @head: head of the stack
 * @line_number: line number
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	(void) line_number;

	if (*head == NULL)
		return;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
