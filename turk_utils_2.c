/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:31 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/19 13:45:41 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_prev_biggest(t_stack *stack, t_stack *node)
{
	t_stack	*next_biggest;
	t_stack	*tmp;

	next_biggest = NULL;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr > node->nbr && (next_biggest == NULL
				|| tmp->nbr < next_biggest->nbr))
			next_biggest = tmp;
		tmp = tmp->next;
	}
	if (next_biggest == NULL)
		return (get_smallest(stack));
	return (next_biggest);
}

void	move_back_to_a(t_ps *l)
{
	t_stack	*next_biggest;

	while (l->b)
	{
		next_biggest = get_prev_biggest(l->a, l->b);
		if (next_biggest != l->a)
			rotate_a_to_top(l, next_biggest);
		pa(l);
	}
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_big_nbr(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	exec_rr_rrr(t_ps *l, int c_rr, int c_rrr)
{
	if (c_rrr == 1)
		rra(l);
	else if (c_rrr == 2)
		rrb(l);
	else if (c_rrr == 3)
		rrr(l);
	if (c_rr == 1)
		ra(l);
	else if (c_rr == 2)
		rb(l);
	else if (c_rr == 3)
		rr(l);
}
