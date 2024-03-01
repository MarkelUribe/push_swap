/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:23:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/01 16:26:17 by muribe-l         ###   ########.fr       */
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
	if (size / 2 < pos)
		distance = pos;
	else
		distance = size - pos;
	return (distance);
}

t_stack	*get_next_smallest(t_stack *stack, t_stack *node)
{

}

void	calc_cost(t_ps *l)
{
	t_stack	*tmp;
	int		cost;

	tmp = l->a;
	while (tmp)
	{
		cost = 0;
		tmp->cost = get_distance(l->a, tmp) +
			get_distance(l->b, get_next_smallest(l->b, tmp));
		tmp = tmp->next;
	}
}

void	turk_sort(t_ps *l)
{
	pb(l);
	pb(l);
	while (stacksize(l->a) > 3)
	{
		calc_cost(l);
	}
}