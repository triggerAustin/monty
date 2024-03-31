#include "monty.h"

values value_holder = {NULL, 0, 0, NULL};

/**
 * main -  takes in file as argument
 * argv: argument vector
 * argc: argument count
 */
int main(int argc, char *argv[])
{
	char *filename = argv[1];
	stack_t **stack;
    
	if (argc < 2)
	{
		/*output error*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack= malloc(sizeof(stack_t *));
	if(!stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(filename);
		exit(EXIT_FAILURE);
	}
	
	*stack = NULL;
	value_holder.file = fopen(filename, "r");/*open the file*/

	if (value_holder.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(filename);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	process_monty(stack);/*process the monty file*/ 
	fclose(value_holder.file);
	free_stack(stack);
	free(stack);
	return (0); 
}

