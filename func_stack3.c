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
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	i = (tmp->next->n) - (tmp->n);
	tmp->next->n = i;
	free(*head);
	*head = tmp->next;
}
/**
 * f_div - divides the second top element of the stack by the
 * top element of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
void f_div(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int i;

	if (tmp == NULL || tmp->next == NULL)
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	else if ((tmp->next->n) == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}

	i = (tmp->next->n) / (tmp->n);
	tmp->next->n = i;
	free(*head);
	*head = tmp->next;
}
/**
 * f_mul - multiplies the second top element of the stack with the
 * top element of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
void f_mul(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int i;

	if (tmp == NULL || tmp->next == NULL)
	{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}

	i = (tmp->next->n) * (tmp->n);
	tmp->next->n = i;
	free(*head);
	*head = tmp->next;
}
/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 */
void f_mod(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int i;

	if (tmp == NULL || tmp->next == NULL)
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	else if ((tmp->next->n) == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	i = (tmp->next->n) % (tmp->n);
	tmp->next->n = i;
	free(*head);
	*head = tmp->next;
}
/**
 * pchar - prints the char at the top of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 */
void pchar(stack_t **head, unsigned int line_number)
{
	int i = (*head)->n;

	if ((i >= 65 && i <= 90) || (i >= 65 && i <= 90))
	{
	printf("%c\n", (char)i);
	}
	else if (*head == NULL)
	{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	else
	{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
}
