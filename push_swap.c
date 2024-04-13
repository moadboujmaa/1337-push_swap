/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/13 20:10:00 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		fill_stack(&stack_a, argv + 1);
		if (is_sorted(&stack_a))
			exit(0);
		printf("stack_a after:\n");
		ft_print_stack(&stack_a);
		push_swap(&stack_a, &stack_b);
	}
	return (0);
}
