/* main.c */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int x;
	int y;
	int z;
	int *p = &x;
	int *p2 = &y;
	int *p3 = &z;
	x = 5;
	y = 6;
	z = 7;
	t_list *lst;
	lst = ft_lstnew(p);
	t_list *node = ft_lstnew(p2);
	ft_lstadd_front(&lst,node);

	ft_lstadd_back(&lst,ft_lstnew(p3));

	t_list *last;
	last = ft_lstlast(lst);
	printf("%d", *((int *)(last->content)));
}
