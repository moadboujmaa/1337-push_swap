/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:24:00 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/13 17:16:57 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_newitem(int content, int index)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->nb = content;
	ptr->index = index;
	ptr->next = NULL;
	return (ptr);
}

void	ft_addback(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_getlast(*lst)->next = new;
}

t_stack	*ft_getlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_sizelst(t_stack *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_addfront(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
