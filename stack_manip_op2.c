#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to head of stack
 * @count: line count on monty file
 */
void _nop(stack_t **head, unsigned int count)
{
	(void)count;
	(void)head;
}

/**
 * pstr- print the string of the stack element ascii value
 * @head: pointer to top of stack
 * @count: line number in monty file
 */
void _pstr(stack_t **head, unsigned int count)
{
	stack_t *current = *head;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pstr, stack empty", count);
		exit(EXIT_FAILURE);
	}

	while (current)
	{
		if (current->n >= 0 || current->n <= 127)
			putchar(current->n);
		else
			break;
		current = current->next;
	}
}

/**
 * pchar - prints the ascii value of stack element
 * @head: pointer  to head of stack
 * @count: line number in monty file
 */
void _pchar(stack_t **head, unsigned int count)
{
	(void)count;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't ptchar, stack empty\n", count);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n <= 127 || (*head)->n >= 0)
	{
		putchar((char)(*head)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", count);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pint- prints top stack element
 * @head: pointer to top of stack
 * @line_count: line number on monty file
 */
void _pint(stack_t **head, unsigned int line_count)
{
	if (*head == NULL) {
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
