/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:49:14 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/29 18:58:33 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dumb_sort(t_ps *l)
{
	t_stack	*small;

	while (stacksize(l->a) > 1)
	{
		if (stacksize(l->a) == 2)
		{
			if (l->a->nbr < l->a->next->nbr)
				break ;
		}
		small = get_smallest(l->a);
		if (l->a == small)
			pb(l);
		if (get_pos(l->a, small) > stacksize(l->a) / 2)
			rra(l);
		else
			ra(l);
	}
	while (stacksize(l->b) > 0)
		pa(l);
}
