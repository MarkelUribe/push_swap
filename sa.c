/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:12:10 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 18:50:36 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *l)
{
	t_stack	*tmp;

	if (l->a != NULL && l->a->next != NULL)
	{
		tmp = l->a->next;
		l->a->next = tmp->next;
		tmp->next = l->a;
		l->a = tmp;
		write(1, "sa\n", 3);
	}
}
