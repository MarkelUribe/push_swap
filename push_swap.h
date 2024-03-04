/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:11:05 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/04 12:42:32 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct t_stack
{
	int				nbr;
	struct t_stack	*next;
	int				index;
	unsigned int	cost;
}	t_stack;

typedef struct t_ps
{
	t_stack	*a;
	t_stack	*b;
}	t_ps;

void	sa(t_ps *l);
void	sb(t_ps *l);
void	ss(t_ps *l);
void	pa(t_ps *l);
void	pb(t_ps *l);
void	swap(t_stack *a1, t_stack *a2);
void	ra(t_ps *l);
void	rb(t_ps *l);
void	rr(t_ps *l);
void	rra(t_ps *l);
void	rrb(t_ps *l);
void	rrr(t_ps *l);
void	free_all(t_ps *l);
void	error_free(t_ps *l);
void	free_split(char **array);
t_stack	*stacknew(int nbr);
t_stack	*stacklast(t_stack *lst);
int		stacksize(t_stack *lst);
void	stackadd_back(t_stack **lst, t_stack *new);
void	stackadd_front(t_stack *lst, t_stack *new);
void	fill_stack(t_ps *l, char **args, int argc);
void	dumb_sort(t_ps *l);
void	turk_sort(t_ps *l);
void	apply_index(t_ps *l);
int		get_pos(t_stack *stack, t_stack *target);
t_stack	*get_smallest(t_stack *stack);
t_stack	*get_next_smallest(t_stack *stack, t_stack *node);
#endif