#include "monty.h"

/**
 * get_func_operation - takes in a tokenized potion of
 * monty code and calls the corresponding fn
 * @token: a tokenized portion of monty code
 * @stack: the stack to be worked on
 */
void get_func_operations(char *token, stack_t **stack)
{
	unsigned int i = 0, c;
	char *t;

	instruction_t func_operations[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mod", _mod},
		{"div", _div},
		{"mul", _mul},
		{"pstr", _pstr},
		{"pchar", _pchar},
		{"none", NULL}
	};
	while ((token && func_operations[i].opcode))
	{
		if (strcmp(token, func_operations[i].opcode) == 0)
		{
			func_operations[i].f(stack, value_holder.line_count);
			return;
		}
		else if (strcmp(func_operations[i].opcode, "none") == 0)
		{
			t = token;
			c = value_holder.line_count;
			fprintf(stderr, "L%u: unknown instruction %s\n", c, t);
			exit(EXIT_FAILURE);
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
	unsigned int count = 0;
	char line[256], *token;
	char delimeters[] = " \t\n";

	/*read file*/
	while (fgets(line, 256, value_holder.file) != NULL)
	{
		count++;
		value_holder.line_val = line;/*store line*/
		value_holder.line_count = count;/*store line count*/

		token = strtok(value_holder.line_val, delimeters);
		/*check if line is a comment return to callling fn*/
		if (token && token[0] == '#')
			return (0);

		value_holder.argument = strtok(NULL, delimeters);
		get_func_operations(token, stack);/*pass to get fn associated with token*/
	}
	return (0);
}
