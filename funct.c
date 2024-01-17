#include "monty.h"
exter_var ex_var;
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
	char *buff;

	file = fopen(filename, "r");
	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s", filename);
	exit(EXIT_FAILURE);
	}
	while ((getline(&buff, &len, file)) != -1)
	{
	ex_var.buf = buff;
	counter++;
	if (ex_var.buf == NULL)
		break;
	functions(&stack, counter);
	}
	free(ex_var.buf);
	fclose(file);
}
/**
 * functions - determine which func or ope is called
 * @stack: doubly linked list of data
 * @counter: number of line
 * Return: void
 */
int functions(stack_t **stack, unsigned int counter)
{
	unsigned int i = 0;
	char *token;
	instruction_t oper_list[] = {
		{"push", f_push},
		{"pall", f_pall},
		{NULL, NULL}};

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
