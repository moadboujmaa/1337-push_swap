/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/18 11:34:45 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	get_min(t_stack *stack)
{
	int	index;
	int	i;
	int	min;

	index = 0;
	i = 0;
	min = stack->nb;
	while (stack)
	{
		if (stack->nb < min)
		{
			index = i;
			min = stack->nb;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

void	multi_move(t_stack **stack, char *move, int nb)
{
	int	i;

	i = 0;
	if (ft_strncmp(move, "ra", 2))
	{
		while (i < nb)
		{
			ra(stack);
			i++;
		}
	}
	else
	{
		while (i < nb)
		{
			rra(stack);
			i++;
		}
	}
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sort_stack(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	top = *stack;
	tmp = *stack;
	*stack = (*stack)->next;
	while (*stack)
	{
		while ((tmp->nb != (*stack)->nb))
		{
			if (tmp->nb > (*stack)->nb)
				ft_swap(&tmp->nb, &(*stack)->nb);
			tmp = tmp->next;
		}
		tmp = top;
		*stack = (*stack)->next;
	}
	*stack = top;
}

void	copy_sort_stack(t_stack *original, t_stack **new)
{
	t_stack	*top;
	int		i;

	i = 0;
	top = original;
	while (original)
	{
		ft_addback(new, ft_newitem((original)->nb, 0));
		original = (original)->next;
	}
	sort_stack(new);
	top = *new;
	while (*new)
	{
		(*new)->index = i;
		i++;
		*new = (*new)->next;
	}
	*new = top;
}
