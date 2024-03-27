/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/27 11:48:54 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack	t_stack;

struct s_stack
{
	int		nb;
	t_stack	*next;
};

// instructions
void	swap(t_stack *stack);
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
// utils
t_stack	*ft_newitem(int content);
void	ft_addback(t_stack **lst, t_stack *new);
t_stack	*ft_getlast(t_stack *lst);
int		ft_sizelst(t_stack *lst);
void	ft_rm_last(t_stack **stack);

#endif
