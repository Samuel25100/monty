#include "monty.h"
/**
 * reader - read monty file and tokenized them
 * @filename: name of the file
 * Return: void
 */
void reader(char *filename)
{
	FILE *file;
	size_t len = 0;
	unsigned int counter = 0;
	stack_t *stack = NULL;

	file = fopen(filename, "r");
	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s", filename);
	exit(EXIT_FAILURE);
	}
	while ((getline(&ex_var.buf, &len, file)) != -1)
	{
	counter++;
	if (ex_var.buf == NULL)
		break;
	functions(&stack, counter);
	}
	free(ex_var.buf);
	free_stack(stack);
	fclose(file);
}
/**
 * functions - determine which func or ope is called
 * @stack: doubly linked list of data
 * @counter: number of line of monty file
 * Return: void
 */
int functions(stack_t **stack, unsigned int counter)
{
	unsigned int i = 0;
	char *token;
	instruction_t oper_list[] = {
		{"push", f_push}, {"pall", f_pall},
		{"pint", f_pint}, {"pop", f_pop},
		{"swap", f_swap}, {NULL, NULL}};

	token = strtok(ex_var.buf, "\n ");
	if (token && token[0] == '#')
		return (0);
	ex_var.arg = strtok(NULL, "\n ");
	while (oper_list[i].opcode && token)
	{
	if (strcmp(token, oper_list[i].opcode) == 0)
		{
		oper_list[i].f(stack, counter);
		break;
		}
	i++;
	}
	return (0);
}
/**
 * free_stack - free doubly linked list of monty data
 * @head: pointer to head
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
