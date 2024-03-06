/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:28:35 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/06 19:34:19 by muribe-l         ###   ########.fr       */
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
	if ((get_pos(l->a, nodea) < stacksize(l->a) / 2
			&& get_pos(l->b, nodeb) < stacksize(l->b) / 2)
		|| (get_pos(l->a, nodea) > stacksize(l->a) / 2
			&& get_pos(l->b, nodeb) > stacksize(l->b) / 2))
		return (1);
	else
		return (0);
}

void	rotate_a_to_top(t_ps *l, t_stack *node)
{
	int	s_pos;
	int	size;

	if (!node || l->a == node)
		return ;
	s_pos = get_pos(l->a, node);
	size = stacksize(l->a);
	while (l->a != node)
	{
		if (s_pos > size / 2 + 1)
			rra(l);
		else
			ra(l);
	}
}

void	rotate_b_to_top(t_ps *l, t_stack *node)
{
	int	s_pos;
	int	size;

	if (!node || l->b == node)
		return ;
	s_pos = get_pos(l->b, node);
	size = stacksize(l->b);
	while (l->b != node)
	{
		if (s_pos > size / 2 + 1)
			rrb(l);
		else
			rb(l);
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
