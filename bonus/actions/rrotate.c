/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:14:40 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/18 11:34:59 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rrotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;
	t_stack	*prev;

	top = *stack;
	last = ft_getlast(*stack);
	prev = NULL;
	while ((*stack)->next)
	{
		prev = *stack;
		*stack = (*stack)->next;
	}
	prev->next = NULL;
	last->next = top;
	top = last;
}

int	rra(t_stack **stack)
{
	if (ft_sizelst(*stack) == 0)
		return (0);
	rrotate(stack);
	return (1);
}

int	rrb(t_stack **stack)
{
	if (ft_sizelst(*stack) == 0)
		return (0);
	rrotate(stack);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_sizelst(*stack_a) == 0 || ft_sizelst(*stack_b) == 0)
		return (0);
	rrotate(stack_a);
	rrotate(stack_b);
	return (1);
}
