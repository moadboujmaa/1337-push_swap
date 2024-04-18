/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:04:27 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/18 11:34:40 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	index_stack(t_stack **stack_a, t_stack *indexed)
{
	t_stack	*top_stack;
	t_stack	*top_indexed;

	top_stack = *stack_a;
	top_indexed = indexed;
	while (*stack_a)
	{
		while (indexed)
		{
			if (indexed->nb == (*stack_a)->nb)
			{
				(*stack_a)->index = indexed->index;
				break ;
			}
			indexed = indexed->next;
		}
		indexed = top_indexed;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = top_stack; 
}

int	get_range(int len)
{
	if (len <= 30)
		return (1);
	else if (len <= 250)
		return (len * 15 / 100);
	else
		return (len * 8 / 100);
}

int	get_max_index(t_stack *stack)
{
	int	max;
	int	i;
	int	index;

	index = 0;
	i = 0;
	max = stack->nb;
	while (stack)
	{
		if (stack->nb > max)
		{
			index = i;
			max = stack->nb;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

void	push_2_b(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	while (*stack_a)
	{
		if (((*stack_a)->index <= max) && ((*stack_a)->index >= min))
		{
			pb(stack_a, stack_b);
			min++;
			max++;
		}
		else if ((*stack_a)->index > max)
			ra(stack_a);
		else if ((*stack_a)->index < min)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			min++;
			max++;
		}
	}
}

void	push_2_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	lst_size;

	while (*stack_b)
	{
		max_index = get_max_index(*stack_b);
		lst_size = ft_sizelst(*stack_b);
		if (max_index == 0)
			pa(stack_a, stack_b);
		else if (max_index > lst_size / 2)
			rrb(stack_b);
		else
			rb(stack_b);
	}
}
