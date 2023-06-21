#include "monty.h"
/**
 * pstr - prints data in the stack
 * @head: head of the stack
 * @line_number: line number
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void) line_number;

	if (head == NULL)
		return;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->n > 31 && temp->n < 128)
			printf("%c", temp->n);
		else
			break;
		temp = temp->next;
	}
	printf("\n");
}
