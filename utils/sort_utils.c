/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/13 22:43:24 by mboujama         ###   ########.fr       */
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
