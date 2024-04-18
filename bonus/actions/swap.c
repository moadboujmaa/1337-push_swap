/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:05:48 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/18 11:35:02 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp;

	head = *stack;
	next = (*stack)->next;
	tmp = head->nb;
	head->nb = next->nb;
	next->nb = tmp;
}

int	sa(t_stack **stack)
{
	if (ft_sizelst(*stack) <= 1)
		return (0);
	swap(stack);
	return (1);
}

int	sb(t_stack **stack)
{
	if (ft_sizelst(*stack) <= 1)
		return (0);
	swap(stack);
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_sizelst(*stack_a) <= 1 && ft_sizelst(*stack_b) <= 1)
		return (0);
	swap(stack_a);
	swap(stack_b);
	return (1);
}
