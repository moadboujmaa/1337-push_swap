/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:05:17 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/17 12:16:30 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mandatory/push_swap.h"

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;

	if (*stack_b == NULL)
		return (0);
	top = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_addfront(stack_a, top);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;

	if (*stack_a == NULL)
		return (0);
	top = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_addfront(stack_b, top);
	ft_printf("pb\n");
	return (1);
}
