#include "monty.h"

/**
 * free_list - frees getline list
 * @a: pointer to array of strings
 * Return: Nothing
 */
void free_list(char *a[])
{
	int i = 0;

	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
}
