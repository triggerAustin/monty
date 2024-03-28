#include "monty.h"

/**
 * get_func_operation - takes in a tokenized potion of monty code and calls the corresponding fn
 * @token: a tokenized portion of monty code
 * @stack: the stack to be worked on
 */
void get_func_operations(char *token, stack_t **stack)
{
	unsigned int i = 0;

	instruction_t func_operations[] = {
		{"push", _push},
		{"pall", _pall}, 
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul}
	};
	while((token && func_operations[i].opcode))
	{
	    if(strcmp(token, func_operations[i].opcode) == 0)
	    {
	        func_operations[i].f(stack, value_holder.line_count);
	        return;
	    }
	    else if(strcmp(token, "none") == 0)
	    {
	        fprintf(stderr, "L%u: unknown instruction", value_holder.line_count);
	    }
	    i++;
	}
 }

/**
 * process_monty - processes the single line of the monty file,
 * passing it to get_func_operation
 * @stack: stack to be worked on
 * @line: line number on being processed
 * @return: return 0 if successful
 */
int process_monty(stack_t **stack)
{
    char *token;
    char delimeters[] = " \t\n";
    token = strtok(value_holder.line_val, delimeters);
    
    if(token && token[0] == '#')/*check if line is a comment return to callling fn*/
        return (0);
    
    value_holder.argument = strtok(NULL, delimeters);/*if operand exists, store in this variable*/
    get_func_operations(token, stack);/*pass to get fn associated with token*/
    return (0);
}
