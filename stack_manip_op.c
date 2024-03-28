#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @head: pointer to stack_t
 * @line_count: line number on monty file being worked on
 */
void _pop(stack_t **head, unsigned int line_count)
{
	stack_t *temp;

	if(!*head || (*head) == NULL)
	{
		fprintf(stderr, "L%u: cannot pop element, stack empty", line_count);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));

	if(temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
 
/**
 * _push - pushes a value to top of stack
 * @head: pointer to stack
 * @line_count: line number being worked on
 */
void _push(stack_t **head, unsigned int line_count)
{  
	int val;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if(!new_node)
	{
		printf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	
	/*check if value to be pushed exists and is int*/
	if(!value_holder.argument || !(_isint(value_holder.argument)))
	{
		fprintf(stderr, "L%u: usage: push integer \n", line_count);
		exit(EXIT_FAILURE);
	}
	else
	{
		val = atoi(value_holder.argument);
		addnode(head, val);
	}
    /*free(value_holder.argument);*/
}
  
/**
 * _pall - prints the stack
 * @head: pointer to head of stack
 * @line_count: line in monty file
 */
void _pall(stack_t **head, unsigned int line_count)
{
	stack_t *current;
	(void)line_count;/*because it is not used*/
	
	/*check if stack is empty print nothing if so*/
	if(*head == NULL)
		exit(EXIT_FAILURE);
    	
	current = *head;
	
	while(current)
	{
		printf("%d\n", current->n);/*print*/
		current = current->next;
	}
}
   
/**
 * _pint - prints the top value in stack
 * @head: pointer to stack
 * @line_count: line number in monty file 
 */
void _pint(stack_t **head, unsigned int line_count)
{
	if((*head) == NULL)
	{
		fprintf(stderr, "L%u: pointer to stack is NULL\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d/n", (*head)->n);
}

/**
 * _swap - swaps the two top values
 * @head: pointer to head of stack
 * @line_count: line number in monty file
 */
void _swap(stack_t **head, unsigned int line_count)
{
	int temp;

	if(!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: stack too short, couldn't perform action", line_count);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}

/**
 * addnode - adds a node to the stack
 * @head: pointer to stack
 * @n: value to add to node
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));/*allocate memory to the new node*/

	/*check malloc fail*/
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;/*updating head of stack to pint to new_node*/
	new_node->next = *head;
	new_node->prev = NULL;

	/*check is stack is empty before adding a new node*/
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;

}
