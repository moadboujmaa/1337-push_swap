/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/27 14:48:53 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_errors(int argc, char **argv)
{
	(void) 
	if (argc < 2)
		ft_printf("Error: require numbers\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b;

	main_errors(argc, argv);
	fill_stack(&stack_a, argv);
	return (0);
}
