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
	     fprintf(stderr, "Error: malloc failed");
	     exit(EXIT_FAILURE);
     }
    /*check if value to be pushed exists*/
    if(!value_holder.argument)
    {
        fprintf(stderr, "L%u: usage: No value to push\n", line_count);
        exit(EXIT_FAILURE);
    }
    /*convert to int and push*/
    if(_isint(value_holder.argument))
    {
        val = atoi(value_holder.argument);
       addnode(head, val);

    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer", line_count);
        exit(EXIT_FAILURE);
    }
    /*free(value_holder.argument);*/
 }
  
/**
 * 
 * 
 */
void _pall(stack_t **head, unsigned int line_count)
{
    stack_t *current;
	if(*head == NULL)
	{
		fprintf(stderr, "L%u: pointer to stack is NULL\n", line_count);
		exit(EXIT_FAILURE);	
	}
    	
	current = *head;
	
	while(current)
	{
	    printf("%d\n", current->n);/*print*/
		current = current->next;
	}
}
   
/**
 * 
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
 * 
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
void addnode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));/*allocate memory to the new node*/

	if (new_node == NULL)/*node is empty*/
	{
	printf("Error\n");/*error*/
	exit(0);
	}
	new_node->n = n;/*updating head of stack to pint to new_node*/
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)/*check is stack is empty before adding a new node*/
	(*head)->prev = new_node;
	*head = new_node;
}
