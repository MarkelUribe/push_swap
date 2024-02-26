/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:52:38 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/26 13:43:45 by muribe-l         ###   ########.fr       */
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
		if (smallest->content > tmp->content)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

void	order(t_ps *l)
{
	t_stack	*small;

	while (stacksize(l->a) > 1)
	{
		small = get_smallest(l->a);
		if (l->a == small)
			pb(l);
		ra(l);
	}
	while (stacksize(l->b) > 0)
		pa(l);
}
