/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/12 16:42:22 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap(t_stack **stack_a, t_stack **stack_b)
// {}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void) stack_b;
	if (argc >= 2)
	{
		fill_stack(&stack_a, argv + 1);
		if (is_sorted(&stack_a))
			exit(0);

		printf("stack_a:\n");
		ft_print_stack(&stack_a);
		printf("stack_b:\n");
		ft_print_stack(&stack_b);
	}
	return (0);
}
