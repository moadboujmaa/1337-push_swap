/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:04:27 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/15 16:17:58 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (len < 30)
		return (2);
	else
		return (0.035 * len + 15);
}

void	push_2_b(t_stack **stack_a, t_stack **stack_b, int *min, int *max)
{
	while (*stack_a)
	{
		if (!((*stack_a)->index >= *max) && !((*stack_a)->index <= *min))
		{
			pb(stack_a, stack_b);
			min++;
			max++;
		}
		else if ((*stack_a)->index > *min)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			min++;
			max++;
		}
	}
}
