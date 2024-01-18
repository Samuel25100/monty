#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @head: @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	int i;
	stack_t *tmp = *head;

	(void)line_number;
	if (*head == NULL)
		printf("\n");
	else
	{
		while (tmp)
		{
		i = tmp->n;
		if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
			printf("%c", (char)i);
		else
			break;
		tmp = tmp->next;
		}
		printf("\n");
	}
}
