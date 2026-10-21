/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int x;
	int y;
	int *p = &x;
	int *p2 = &y;
	x = 5;
	y = 6;
	t_list *lst;
	lst = ft_lstnew(p);
	t_list *node = ft_lstnew(p2);
	ft_lstadd_front(&lst,node);

	printf("%d",*((int *)(lst->next->content)));
	return (0);
}
