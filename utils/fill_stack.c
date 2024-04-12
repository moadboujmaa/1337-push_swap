/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/12 16:43:21 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	ft_print_stack(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		ft_printf("{%d}\n", current->nb);
		current = current->next;
	}
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

void	fill_stack(t_stack **stack, char **arr_nb)
{
	char	**numbers;
	int		i;

	i = 0;
	if (ft_strchr(arr_nb[0], ' '))
		numbers = ft_split(arr_nb[0], ' ');
	else
		numbers = arr_nb;
	while (numbers[i])
	{
		if (ft_isnumber(numbers[i]))
			ft_addfront(stack, ft_newitem(ft_atoi(numbers[i])));
		else
			print_error();
		i++;
	}
	if (numbers != arr_nb)
	{
		i = 0;
		while (numbers[i])
			free(numbers[i++]);
		free(numbers);
	}
	if (is_duplicated(stack))
		print_error();
}
