#include "monty.h"

/**
 * _add - adds two top values of the stack
 * @head: pointer to head of stack
 * 
 */
 void _add(stack_t **head, unsigned int count)
{
	stack_t *val1, *val2;

	if(!head || (*head) == NULL || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
    /*take first two values*/
    val1 = *head;
    val2 =  (*head)->next;
    
    val1->n += val2->n;/*add values*/
    free(val2);
    /*put results to top of stack*/
    *head = val1;
}

/**
 * _sub - subtracts the top two values of the stack
 * @head: pointer to top of stack
 * 
 */
void _sub(stack_t **head, unsigned int count)
{ 
    stack_t *val1, *val2;
    
    if(!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't subtract, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
    
    /*take two values from top*/
    val1 = *head;
    val2 = (*head)->next;
    
    val1->n -= val2->n;
    *head = val1;
}

/**
 * 
 * 
 */
void _div(stack_t **head, unsigned int count)
{
    stack_t *val1, *val2;
    
    if(!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u can't divide, stack too short", count);
		exit(EXIT_FAILURE);
	}
	
	/*take two values from top*/
    val1 = *head;
    val2 = (*head)->next;
    if(val2->n == 0)
    {
        fprintf(stderr, "l%u, zero division", count);
        exit(EXIT_FAILURE);
    }
    
    val1->n /= val2->n;
    free(val2);
    *head = val1;
}

/**
 * 
 * 
 * 
 */
void _mul(stack_t **head, unsigned int count)
{
    stack_t *val1, *val2;
    
    if(!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't multiply, stack too short", count);
		exit(EXIT_FAILURE);
	}
	
	/*take two values from top*/
    val1 = *head;
    val2 = (*head)->next;
    
    val1->n *= val2->n;
    *head = val1;
}
