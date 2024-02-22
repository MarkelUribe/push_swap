/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:00 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/22 17:05:28 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_ps *l)
{
	int		i;
	t_stack	*lst;
	t_stack	*last;

	if (!l->b || !l->b->next)
		return ;
	last = stacklast(l->b);
	lst = l->b;
	i = 0;
	while (i < stacksize(l->b) - 2)
	{
		lst = lst->next;
		i++;
	}
	lst->next = NULL;
	last->next = l->b;
	l->b = last;
	write(1, "rrb\n", 4);
}
