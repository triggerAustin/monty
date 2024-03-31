
#include "monty.h"

/**
 * 
 * 
 */
int _isint(char *value)
{
	if (value == NULL)
		return 0;

	int j = 0, checker;
	if(value[0] == '-')
	{
		j++;
	}
	for(; value[j] != '\0'; j++)
	{
		if(value[j] <= 57 && value[j] >= 48)
			checker = 1;
		else
			checker = 0;
	}
	return (checker);
}
