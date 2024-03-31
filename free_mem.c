#include "monty.h"

/**
 * free_stack - frees mem of anything associated with stack
 * @head: pointer to head of stack
 */
void free_stack(stack_t **head)
{
    stack_t *current = *head;
    stack_t *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
 
}
