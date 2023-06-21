#include "monty.h"
/**
 * pstr - prints data in the stack
 * @head: head of the stack
 * @line_number: line number
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	(void) line_number;

	if (*head == NULL)
		return;

	while (temp != NULL)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
