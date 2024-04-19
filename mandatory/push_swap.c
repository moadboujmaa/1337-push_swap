/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/18 15:33:27 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_sizelst(*stack_a) == 2)
		sa(stack_a);
	else if (ft_sizelst(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_sizelst(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_sizelst(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		fill_stack(&stack_a, argv + 1);
		if (is_sorted(&stack_a))
			exit(0);
		push_swap(&stack_a, &stack_b);
		while (stack_a)
		{
			tmp = stack_a->next;
			free(stack_a);
			stack_a = tmp;
		}
	}
	return (0);
}
