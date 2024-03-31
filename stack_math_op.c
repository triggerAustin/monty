#include "monty.h"

/**
 * _add - adds two top values of the stack
 * @head: pointer to head of stack
 * @count: line number in monty file
 */
 void _add(stack_t **head, unsigned int count)
{
	int value;
	stack_t *val;

	if(!head || (*head) == NULL || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	val = (*head)->next;

	value = (*head)->n + val->n;/*add values*/
	
	/*pop top two elements*/
	_pop(head, count);
	_pop(head, count);

	addnode(head, value);
}

/**
 * _sub - subtracts the top two values of the stack
 * @head: pointer to top of stack
 * @count: line number in monty file
 */
void _sub(stack_t **head, unsigned int count)
{
	int value;
	stack_t *val;

	if(!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	val = (*head)->next;
	value = val->n - (*head)->n;

	/*remove top two elements*/
	_pop(head, count);
	_pop(head, count);

	addnode(head, value);
}

/**
 * _div - divides top two values in a stack
 * @head: pointer to head of stack
 * @count: line number in monty file
 */
void _div(stack_t **head, unsigned int count)
{
	int value;
	stack_t *val;

	if(!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u can't div, stack too short", count);
		exit(EXIT_FAILURE);
	}


	if((*head)->n == 0)
	{
		fprintf(stderr, "l%u, division by zero", count);
		exit(EXIT_FAILURE);
	}

	val = (*head)->next;
	value = val->n / (*head)->n;

	/*pop first two elements*/
	_pop(head, count);
	_pop(head, count);

	addnode(head, value);
}

/**
 * _mul - multiplies top two stack values
 * @head: pointer to head of stack
 * @count: line number in monty file
 */
void _mul(stack_t **head, unsigned int count)
{
	int value;
	stack_t *val;
    
	if(!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short", count);
		exit(EXIT_FAILURE);
	}

	/*take two values from top*/
	val = (*head)->next;
	value = val->n * (*head)->n;
	
	/*remove top two elements*/
	_pop(head, count);
	_pop(head, count);
	/*push new value*/
	addnode(head, value);
}

/**
 * _mod - gets the modulous of the top value
 * @head: pointer to head of stack
 * @count: line count in monty file
 */
void _mod(stack_t **head, unsigned int count)
{
	int value;
	stack_t *mod_val;

	if(!*head)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	if((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		exit(EXIT_FAILURE);
	}

	mod_val = (*head)->next;
	value = mod_val->n % (*head)->n;

	/*pop top two elements*/
	_pop(head, count);
	_pop(head, count);

	addnode(head, value);
}
