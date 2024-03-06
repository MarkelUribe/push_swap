/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:23:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/06 19:52:50 by muribe-l         ###   ########.fr       */
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

void	rr_rrr_operations(t_ps *l, t_stack *node, t_stack *next_smallest)
{
	int rrr;
	int	rr;

	rrr = 0;
	rr = 0;
	while (l->a != node && l->b != next_smallest)
	{
		if (get_pos(l->a, node) > stacksize(l->a) / 2)
			rrr = 1;
		else
			rr = 1;

		if (get_pos(l->b, next_smallest) > stacksize(l->b) / 2)
		{
			if (rrr != 0)
				rrr = 3;
			else
				rrr = 2;
		}
		else
		{
			if (rr != 0)
				rr = 3;
			else
				rr = 2;
		}
		exec_rr_rrr(l, rr, rrr);
	}
}

void	move_to_b(t_ps *l, t_stack *node)
{
	t_stack	*next_smallest;

	next_smallest = get_next_smallest(l->b, node);
	//if (is_in_same_half(l, node, next_smallest))
	//	rr_rrr_operations(l, node, next_smallest);
	rotate_a_to_top(l, node);
	rotate_b_to_top(l, next_smallest);
	pb(l);
}

void	sort_last_three(t_ps *l)
{
	t_stack	*a;
	t_stack	*s;
	t_stack	*b;

	if (stacksize(l->a) != 3)
		return ;
	a = l->a;
	s = get_smallest(a);
	b = get_biggest(a);
	if (a->nbr > a->next->nbr && a->next->nbr > a->next->next->nbr)
	{
		sa(l);
		rra(l);
	}
	else if (a == s && a->next == b)
	{
		rra(l);
		sa(l);
	}
	else if (a->next == s && a->next->next == b)
		sa(l);
	else if (a != s)
		rotate_a_to_top(l, s);
}

void	turk_sort(t_ps *l)
{
	if (stacksize(l->a) < 3)
	{
		rotate_a_to_top(l, get_smallest(l->a));
		exit(0);
	}
	if (stacksize(l->a) > 4)
	{
		pb(l);
		pb(l);
	}
	else if (stacksize(l->a) == 4)
		pb(l);
	while (stacksize(l->a) > 3 && !is_sorted(l->a))
	{
		calc_cost(l);
		move_to_b(l, get_smallest_cost(l->a));
	}
	sort_last_three(l);
	move_back_to_a(l);
	rotate_a_to_top(l, get_smallest(l->a));
}
