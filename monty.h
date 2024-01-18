#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct exter_variable - global variable that hold push arguments
 * and buffer from getline
 * @push_arg: push arguments
 * @buf: buffer from getline
 */
typedef struct external_variable
{
	int push_arg;
	char *arg;
	char *buf;
}exter_var;

extern exter_var ex_var;

	/*Functions*/
int is_num(char *str);
void *my_calloc(size_t num_el, size_t size_el);
void reader(char *filename);
int functions(stack_t **head, unsigned int counter);
char *_strdup(char *str);
void add_nodeint(stack_t **head);
void free_stack(stack_t *head);
	/*Monty Functions*/
void f_push(stack_t **head, unsigned int line_number);
void f_pall(stack_t **head, unsigned int line_number);
void f_pint(stack_t **head, unsigned int line_number);
void f_pop(stack_t **head, unsigned int line_number);
void f_swap(stack_t **head, unsigned int line_number);
void f_add(stack_t **head, unsigned int line_number);
#endif
