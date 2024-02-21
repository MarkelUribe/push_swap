/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:56:54 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 19:21:57 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *l)
{
	int	i;
	t_stack *lst;
	t_stack *last;

	if (!l->a && !l->a->next)
		return ;
	last = stacklast(l->a);
	i = 0;
	while (i > stacksize(l->a) - 1)
	{
		lst = lst->next;
		i--;
	}
	lst->next = NULL;
	last->next = l->a;
	write(1, "rra\n", 4);
}
