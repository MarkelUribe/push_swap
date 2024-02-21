/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:51:31 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 19:58:55 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_ps *l)
{
	t_stack	*d;

	if (l->b != NULL && l->b->next != NULL)
	{
		d = l->b;
		l->b = l->b->next;
		d->next = NULL;
		stacklast(l->b)->next = d;
		write(1, "rb\n", 3);
	}
}
