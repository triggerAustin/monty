#include "monty.h"

/**
 * _isint - checks if value is int
 * @value: value to check
 */
int _isint(char *value)
{
	int checker, j = 0;

	if (value == NULL)
		return (0);

	if (value[0] == '-')
	{
		j++;
	}
	for (; value[j] != '\0'; j++)
	{
		if (value[j] <= 57 && value[j] >= 48)
			checker = 1;
		else
			checker = 0;
	}
	return (checker);
}
