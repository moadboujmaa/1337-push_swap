/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:46 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/27 14:44:14 by mboujama         ###   ########.fr       */
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
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack);
int		rb(t_stack **stack);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack);
int		rrb(t_stack **stack);
int		rrr(t_stack **stack_a, t_stack **stack_b);

// utils
t_stack	*ft_newitem(int content);
void	ft_addback(t_stack **lst, t_stack *new);
t_stack	*ft_getlast(t_stack *lst);
int		ft_sizelst(t_stack *lst);
void	ft_addfront(t_stack **lst, t_stack *new);

// fill stack
void	fill_stack(t_stack **stack, char **argv);
int		is_sorted(t_stack **stack);
int		is_duplicated(t_stack **stack);

#endif
