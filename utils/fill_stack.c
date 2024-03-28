/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/28 11:43:14 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		if (next == NULL)
			return (1);
		if (current->nb > next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_duplicated(t_stack **stack)
{
	t_stack	*current;
	t_stack	*check;

	current = *stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (check->nb == current->nb)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

void	check(t_stack **stack)
{
	if (!is_sorted(stack) || is_duplicated(stack))
		print_error();
}

void	fill_stack(t_stack **stack, char **arr_nb)
{
	char	**numbers;

	if (ft_strchr(arr_nb[0], ' '))
		numbers = ft_split(arr_nb[0], ' ');
	else
		numbers = arr_nb;
	while (*numbers)
	{
		if (ft_isnumber(*numbers))
			ft_addback(stack, ft_newitem(ft_atoi(*numbers)));
		else
			print_error();
		numbers++;
	}
	check(stack);
}
