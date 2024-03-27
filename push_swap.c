/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/27 11:49:07 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_addback(&stack_a, ft_newitem(1));
	ft_addback(&stack_a, ft_newitem(2));
	ft_addback(&stack_a, ft_newitem(3));
	ft_addback(&stack_b, ft_newitem(4));
	ft_addback(&stack_b, ft_newitem(5));
	ft_addback(&stack_b, ft_newitem(6));
	pa(&stack_a, &stack_b);
	while (stack_a)
	{
		printf("a = %d\n", stack_a->nb);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("b = %d\n", stack_b->nb);
		stack_b = stack_b->next;
	}
	return (0);
}
