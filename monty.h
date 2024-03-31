#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
 * values - holds values ot be used out through the program
 * @argument: the value to be pushed onto the stack_t
 * @line_count: the number of lines in the monty file
 * @line_val: the opcode in the monty byte file
 * @file: file being worked on
 */
 typedef struct values
 {
     char *line_val;
     char *argument;
     unsigned int line_count;
     FILE *file;
 } values;
extern values value_holder;
void get_func_operations(char *token, stack_t **stack);
int process_monty(stack_t **stack);
void _free();
int _isint(char *value);
void addnode(stack_t **head, int n);
void _push(stack_t **head, unsigned int line_count);
void _pop(stack_t **head, unsigned int line_count);
void _pall(stack_t **head, unsigned int line_count);
void _pint(stack_t **head, unsigned int line_count);
void _swap(stack_t **head, unsigned int line_count);
void _add(stack_t **head, unsigned int line_count);
void _sub(stack_t **head, unsigned int line_count);
void _mul(stack_t **head, unsigned int line_count);
void _div(stack_t **head, unsigned int line_count);
void _mod(stack_t **head, unsigned int line_count);
void _pchar(stack_t **head, unsigned int line_count);
void _pstr(stack_t **head, unsigned int line_count);
void _nop(stack_t ** head, unsigned int line_count);
void free_stack(stack_t **head);
values value_holder = {NULL, 0, 0, NULL};
#endif

