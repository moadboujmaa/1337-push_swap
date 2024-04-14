/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/14 15:53:47 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
