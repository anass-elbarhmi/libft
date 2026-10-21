#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *lst;
	lst->content = content;
	lst->next = NULL;

	return NULL;
}