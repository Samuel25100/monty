#include "monty.h"
exter_var ex_var;
/**
 * main - take argument from input pass it to functions
 * @argc: the number of argument
 * @argv: the array of each arguments
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	reader(argv[1]);
	return (0);
}
