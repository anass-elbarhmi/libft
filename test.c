/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int x;
	int *p = &x;

	x = 5;
	t_list *lst;
	lst = ft_lstnew(p);
	//printf("%d",(*((int *)(lst->content))));
	printf("%p",lst->next);
	
	return (0);
}
