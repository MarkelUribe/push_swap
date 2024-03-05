/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:23:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/05 13:39:41 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost(t_ps *l)
{
	t_stack	*tmp;
	t_stack	*b;
	int		cost;

	tmp = l->a;
	while (tmp)
	{
		cost = 0;
		b = get_next_smallest(l->b, tmp);
		if (is_in_same_half(l, tmp, b))
			cost = get_distance(l->a, tmp) - get_distance(l->b, b) + 1;
		else
			cost = get_distance(l->a, tmp) + get_distance(l->b, b) + 1;
		if (cost < 0)
			cost *= -1;
		tmp->cost = (unsigned int)cost;
		tmp = tmp->next;
	}
}

void	move_to_b(t_ps *l, t_stack *node)
{
	t_stack	*next_smallest;
	int		a_pos;
	int		b_pos;
	int		i;

	next_smallest = get_next_smallest(l->b, node);
	if (!next_smallest)
		next_smallest = get_biggest(l->b);
	a_pos = get_pos(l->a, node);
	b_pos = get_pos(l->b, next_smallest);
	if (is_in_same_half(l, node, next_smallest))
	{
		if (a_pos > b_pos)
			i = b_pos - 1;
		else
			i = a_pos - 1;
		if (a_pos <= stacksize(l->a) / 2)
		{
			while (i--)
				rr(l);
		}
		else
		{
			if (a_pos > b_pos)
				i = stacksize(l->b) - b_pos - 1;
			else
				i = stacksize(l->a) - a_pos - 1;
			while (i--)
				rrr(l);
		}
	}
	rotate_a_to_top(l, node);
	rotate_b_to_top(l, next_smallest);
	pb(l);
}

void	turk_sort(t_ps *l)
{
	if (stacksize(l->a) > 4)
	{
		pb(l);
		pb(l);
	}
	while (stacksize(l->a) > 3)
	{
		calc_cost(l);
		move_to_b(l, get_smallest_cost(l->a));
	}
}
