/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>

t_list *ft_lstlast(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return lst;
}

int main(void)
{
	
	return (0);
}
