/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/18 14:47:43 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	split_and_add(t_stack **stack, char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(str, ' ');
	if (arr == NULL)
		print_error_s(stack);
	i = 0;
	while (arr[i])
	{
		if (ft_isnumber(arr[i]) && (ft_atol(arr[i])
				<= INT_MAX && ft_atol(arr[i]) >= INT_MIN))
			ft_addback(stack, ft_newitem(ft_atol(arr[i]), 0));
		else
			print_error_s(stack);
		i++;
	}
	i = 0;
	free_arr(arr);
}
