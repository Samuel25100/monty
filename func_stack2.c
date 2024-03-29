#include "monty.h"
/**
 * f_pint - print the value at the top of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
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
/**
 * f_pop - removes the top element of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
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
/**
 * f_swap - swaps the top two elements of the stack
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int i;

	if (tmp == NULL || tmp->next == NULL)
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	i = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = i;
}
/**
 * f_add - adds the top two elements of the stack and remove the top
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
void f_add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int i;

	if (tmp == NULL || tmp->next == NULL)
	{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	i = tmp->n;
	i = i + tmp->next->n;
	tmp->next->n = i;
	free(*head);
	*head = tmp->next;
}
/**
 * f_nop - doesn’t do anything
 * @head: pointer to the head
 * @line_number: the number of line at monty
 * Return: void
 */
void f_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	;
}
