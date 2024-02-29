/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:23:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/29 19:04:54 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	get_distance(t_ps *l, t_stack *target)
{

}

void	calc_cost(t_ps *l)
{
	t_stack	*tmp;
	int		cost;
	int		apos;
	int		bpos;

	tmp = l->a;
	while (tmp)
	{
		cost = 0;
		apos = get_pos(l->a, tmp);
		tmp = tmp->next;
	}
}

void	turk_sort(t_ps *l)
{
	pb(l);
	pb(l);
	calc_cost(l);
}