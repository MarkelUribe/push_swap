/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:25:00 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/22 13:26:52 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_ps *l)
{
	int		i;
	t_stack	*lst;
	t_stack	*last;

	if (!l->b && !l->b->next)
		return ;
	last = stacklast(l->b);
	lst = l->b;
	i = 0;
	while (i < stacksize(l->b) - 1)
	{
		lst = lst->next;
		i++;
	}
	lst->next = NULL;
	last->next = l->b;
	write(1, "rrb\n", 4);
}
