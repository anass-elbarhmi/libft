/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

int ft_lstsize(t_list *lst)
{
	int i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return i;
}

int main(void)
{
	
	return (0);
}
