#include "libft.h"
#include <stdlib.h>

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	while (!lst || !del)
	{
		return ;
	}
	
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	
}