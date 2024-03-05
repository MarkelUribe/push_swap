/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:58 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/05 13:51:54 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_smallest(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*tmp;

	smallest = stack;
	tmp = stack;
	while (tmp)
	{
		if (smallest->nbr > tmp->nbr)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

t_stack	*get_biggest(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*tmp;

	biggest = stack;
	tmp = stack;
	while (tmp)
	{
		if (biggest->nbr < tmp->nbr)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}

void	apply_index(t_ps *l)
{
	t_stack	*current;
	t_stack	*tmp;
	t_stack	*candidate;
	int		index;
	int		size;

	size = stacksize(l->a) - 1;
	current = get_smallest(l->a);
	current->index = 1;
	index = 2;
	while (size--)
	{
		candidate = get_biggest(l->a);
		tmp = l->a;
		while (tmp)
		{
			if (tmp->nbr > current->nbr && tmp->nbr < candidate->nbr)
				candidate = tmp;
			tmp = tmp->next;
		}
		current = candidate;
		current->index = index;
		index++;
	}
}

int	get_pos(t_stack *stack, t_stack *target)
{
	t_stack	*tmp;
	int		cost;

	if (!target)
		return (0);
	cost = 1;
	tmp = stack;
	while (tmp)
	{
		if (target == tmp)
			return (cost);
		tmp = tmp->next;
		cost++;
	}
	return (cost);
}

t_stack	*get_next_smallest(t_stack *stack, t_stack *node)
{
	t_stack	*next_smallest;
	t_stack	*tmp;

	next_smallest = NULL;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr < node->nbr && (next_smallest == NULL
				|| tmp->nbr > next_smallest->nbr))
			next_smallest = tmp;
		tmp = tmp->next;
	}
	if (next_smallest == node)
		return (NULL);
	return (next_smallest);
}
