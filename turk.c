/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:23:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/04 13:56:25 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack *stack, t_stack *target)
{
	int	distance;
	int	pos;
	int	size;

	pos = get_pos(stack, target);
	size = stacksize(stack);
	if (pos <= size / 2)
		distance = pos - 1;
	else
		distance = (size - pos) + 1;
	return (distance);
}

int	is_in_same_half(t_ps *l, t_stack *nodea, t_stack *nodeb)
{
	if ((get_pos(l->a, nodea) < stacksize(l->a) / 2 && 
			get_pos(l->b, nodeb) < stacksize(l->b) / 2) ||
			(get_pos(l->a, nodea) > stacksize(l->a) / 2 && 
			get_pos(l->b, nodeb) > stacksize(l->b) / 2))
		return (1);
	else
		return (0);
}

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
			cost =  get_distance(l->a, tmp) + get_distance(l->b, b) + 1;
		if (cost < 0)
			cost *= -1;
		tmp->cost = (unsigned int)cost;
		tmp = tmp->next;
	}
}

t_stack	*get_smallest_cost(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*smallest;

	tmp = stack;
	smallest = stack;
	while (tmp)
	{
		if (tmp->cost < smallest->cost)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

void	rotate_a_to_top(t_ps *l, t_stack *node)
{
	int	s_pos;
	int	size;

	s_pos = get_pos(l->a, node);
	size = stacksize(l->a);
	while (l->a != node)
	{
		if (s_pos > size / 2)
			rra(l);
		else
			ra(l);
	}
}

void	rotate_b_to_top(t_ps *l, t_stack *node)
{
	int	s_pos;
	int	size;

	s_pos = get_pos(l->b, node);
	size = stacksize(l->b);
	while (l->a != node)
	{
		if (s_pos > size / 2)
			rrb(l);
		else
			rb(l);
	}
}
void	move_to_b(t_ps *l, t_stack *node)
{
	t_stack *next_smallest;
	int		a_pos;
	int		b_pos;
	int		i;

	next_smallest = get_next_smallest(l->b, node);
	a_pos = get_pos(l->a, node);
	b_pos = get_pos(l->b, next_smallest);
	if (a_pos > b_pos)
		i = b_pos;
	else
		i = a_pos;
	if (is_in_same_half(l, node, next_smallest))
	{
		
		if (a_pos > stacksize(l->a))
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