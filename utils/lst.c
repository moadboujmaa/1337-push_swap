/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:24:00 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/26 13:10:32 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_newitem(int content)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->nb = content;
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
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_rm_last(t_stack **stack)
{
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	while ((*stack)->next)
	{
		if (!(*stack)->next->next)
			break ;
		*stack = (*stack)->next;
	}
	free((*stack)->next);
	(*stack)->next = NULL;
}
