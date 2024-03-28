#include "monty.h"

/**
 * _free - on call frees memory allocated to members of struct values
 * placed here because they are reusable
 * 
 */
 void _free()
 {
    fclose(value_holder.file);
    free(value_holder.line_val);
 }
void _free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
	_free();
}
