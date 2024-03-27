/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:05:33 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/27 14:08:49 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*top;

	top = *stack;
	*stack = top->next;
	top->next = NULL;
	last = ft_getlast(*stack);
	last->next = top;
}

int	ra(t_stack **stack)
{
	if (ft_sizelst(*stack) == 0)
		return (0);
	rotate(stack);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack)
{
	if (ft_sizelst(*stack) == 0)
		return (0);
	rotate(stack);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_sizelst(*stack_a) == 0 || ft_sizelst(*stack_b) == 0)
		return (0);
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return (1);
}
