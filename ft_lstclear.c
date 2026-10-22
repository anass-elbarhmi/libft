#include "libft.h"
#include <stdlib.h>

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *p_step;
	t_list *p;

	if (!lst || !(*lst) || !del)
	{
		return;
	}
	p = *lst;
	p_step = (*lst)->next;
	while (p_step)
	{
		ft_lstdelone(p, del);
		p = p_step;
		p_step = p_step->next;
	}
	ft_lstdelone(p, del);
	*lst = NULL;
}