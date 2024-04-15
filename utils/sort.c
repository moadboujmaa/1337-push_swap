/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/15 16:04:38 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->nb < (*stack)->next->nb && (*stack)->next->nb
		> (*stack)->next->next->nb && (*stack)->nb < (*stack)->next->next->nb)
	{
		sa(stack);
		ra(stack);
	}
	else if ((*stack)->nb > (*stack)->next->nb && (*stack)->next->nb
		< (*stack)->next->next->nb && (*stack)->nb < (*stack)->next->next->nb)
		sa(stack);
	else if ((*stack)->nb > (*stack)->next->nb && (*stack)->next->nb
		< (*stack)->next->next->nb && (*stack)->nb > (*stack)->next->next->nb)
		ra(stack);
	else if ((*stack)->nb < (*stack)->next->nb && (*stack)->next->nb
		> (*stack)->next->next->nb && (*stack)->nb > (*stack)->next->next->nb)
		rra(stack);
	else 
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = get_min(*stack_a);
	if (min_index == 1)
		sa(stack_a);
	else if (min_index == 2)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (min_index == 3)
		rra(stack_a);
	if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = get_min(*stack_a);
	if (min_index == 1)
		sa(stack_a);
	else if (min_index == 2)
		multi_move(stack_a, "rra", 2);
	else if (min_index == 3)
		multi_move(stack_a, "ra", 2);
	else if (min_index == 4)
		multi_move(stack_a, "ra", 1);
	if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*copy_stack;
	int		min_range;
	int		max_range;

	min_range = 0;
	max_range = get_range(ft_sizelst(*stack_a));
	copy_stack = NULL;
	copy_sort_stack(*stack_a, &copy_stack);
	index_stack(stack_a, copy_stack);
	push_2_b(stack_a, stack_b, &min_range, &max_range);
}
