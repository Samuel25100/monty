#include "monty.h"
/**
 * f_sub - subtracts the top element of the stack from the second
 * top element of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
void f_sub(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int i;

	if (tmp == NULL || tmp->next == NULL)
	{
	fprintf(stderr, "L%u: can't sub, stack too short\n",line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	i = (tmp->next->n) - (tmp->n);
	tmp->next->n = i;
	free(*head);
	*head = tmp->next;
}
