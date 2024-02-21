/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:05:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 19:59:42 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_ps *l)
{
	t_stack	*tmp;

	if (l->b != NULL && l->b->next != NULL)
	{
		tmp = l->b->next;
		l->b->next = tmp->next;
		tmp->next = l->b;
		l->b = tmp;
		write(1, "sb\n", 3);
	}
}
