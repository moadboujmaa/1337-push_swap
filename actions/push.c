/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:05:17 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/27 14:08:21 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack_b == NULL)
		return (0);
	last = *stack_b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev == NULL)
		*stack_b = NULL;
	else
		prev->next = NULL;
	ft_addback(stack_a, last);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack_a == NULL)
		return (0);
	last = *stack_a;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev == NULL)
		*stack_a = NULL;
	else
		prev->next = NULL;
	ft_addback(stack_b, last);
	ft_printf("pb\n");
	return (1);
}
