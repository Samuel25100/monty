#include "monty.h"
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (*head == NULL)
	{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	free(*head);
	*head =	tmp->next;
}
