/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/18 12:50:03 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_move(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strcmp(move, "sa") == 0)
		sa(stack_a);
	else if (ft_strcmp(move, "sb") == 0)
		sb(stack_b);
	else if (ft_strcmp(move, "ss") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(move, "pa") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(move, "pb") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(move, "ra") == 0)
		ra(stack_a);
	else if (ft_strcmp(move, "rb") == 0)
		rb(stack_b);
	else if (ft_strcmp(move, "rr") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(move, "rra") == 0)
		rra(stack_a);
	else if (ft_strcmp(move, "rrb") == 0)
		rrb(stack_b);
	else if (ft_strcmp(move, "rrr") == 0)
		rrr(stack_b, stack_b);
	else
		print_error();
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		fill_stack(&stack_a, argv + 1);
		is_sorted_exit(&stack_a);
		size = ft_sizelst(stack_a);
		str = get_next_line(0);
		while (str)
		{
			do_move(&stack_a, &stack_b, str);
			free(str);
			str = get_next_line(0);
		}
		if (ft_sizelst(stack_a) == size && is_sorted(&stack_a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
