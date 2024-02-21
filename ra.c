/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:10:17 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 19:09:50 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *l)
{
	t_stack *d;

	if (l->a != NULL && l->a->next != NULL)
	{
		d = l->a;
		l->a = l->a->next;
		d->next = NULL;
		stacklast(l->a)->next = d;
		write(1, "ra\n", 3);
	}
}
