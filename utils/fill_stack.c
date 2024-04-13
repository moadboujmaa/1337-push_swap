/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:36:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/13 20:14:46 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(t_stack **stack, char **arr_nb)
{
	int		i;

	i = 0;
	while (arr_nb[i])
	{
		if (ft_strlen(arr_nb[i]) == 0)
			print_error();
		i++;
	}
	i = 0;
	while (arr_nb[i])
	{
		if (ft_strchr(arr_nb[i], ' '))
			split_and_add(stack, arr_nb[i]);
		else
		{
			if ((ft_atol(arr_nb[i]) <= INT_MAX && ft_atol(arr_nb[i]) >= INT_MIN)
				&& ft_isnumber(arr_nb[i]))
				ft_addback(stack, ft_newitem(ft_atol(arr_nb[i]), 0));
			else
				print_error();
		}
		i++;
	}
	if (is_duplicated(stack))
		print_error();
}
