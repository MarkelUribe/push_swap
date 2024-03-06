/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:31 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/06 14:14:44 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_next_biggest(t_stack *stack, t_stack *node)
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
		get_smallest(stack);
	return (next_biggest);
}

void	move_back_to_a(t_ps *l)
{
	t_stack	*next_biggest;

	while (l->b)
	{
		next_biggest = get_next_biggest(l->a, l->b);
		if (next_biggest && next_biggest != l->a)
			rotate_a_to_top(l, next_biggest);
		pa(l);
	}
}