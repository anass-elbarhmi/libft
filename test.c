/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

t_list my_lstnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return NULL;
	new->content = content;
	new->next = NULL;

	return new;
}

int main(void)
{
	
	return (0);
}
