#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @head: head of the stack
 * @line_number: line number
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->prev)
	{
		while ((*head)->prev)
			*head = (*head)->prev;
	}
	if ((*head)->n >= 0 && (*head)->n <= 127)
		printf("%c\n", (*head)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}

}

