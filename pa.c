/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:07:45 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/22 13:10:09 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *l)
{
	t_stack	*tmp;

	if (!l->b)
		return ;
	
	tmp = l->b;
	l->b = l->b->next;
	tmp->next = l->a;
	l->a = tmp;
	write(1, "pa\n", 3);
}
