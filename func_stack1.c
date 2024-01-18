#include "monty.h"
/**
 * f_push - push the int data to stack
 * @head: the doubly linked list of the data structure
 * @line_number: number of line where the command is at in monty
 * Return: void
 */
void f_push(stack_t **head, unsigned int line_number)
{
	if (ex_var.arg == NULL || is_num(ex_var.arg) == 0)
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_stack(*head);
	free(ex_var.buf);
	exit(EXIT_FAILURE);
	}
	else
	{
	ex_var.push_arg = atoi(ex_var.arg);
	add_nodeint(head);
	}
}
/**
 * f_pall - print all stack
 * @head: doubly liked list of data
 * @line_number: number of the line
 * Return: void
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *head;
	if (tmp != NULL)
	{
	while (tmp)
	{
	printf("%d\n", tmp->n);
	tmp = tmp->next;
	}
	}
}
/**
 * add_nodeint - add node to stack
 * @head: pointer to the head
 * Return: void
 */
void add_nodeint(stack_t **head)
{
	stack_t *new, *tmp;

	tmp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}
	if (tmp)
		tmp->prev = new;
	new->n = ex_var.push_arg;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
/**
 * is_num - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int is_num(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
