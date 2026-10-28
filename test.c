/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *head;

	if (!lst || !new)
	{
		return NULL;
	}
	head = *lst;
	while (head->next)
	{
		head = head->next;
	}
	head->next = new;
}

int main(void)
{
	
	return (0);
}
