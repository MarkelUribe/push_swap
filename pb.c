/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:09:41 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/23 16:15:44 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps *l)
{
	t_stack	*tmp;

	if (!l->a)
		return ;
	tmp = l->a;
	l->a = l->a->next;
	tmp->next = l->b;
	l->b = tmp;
	write(1, "pb\n", 3);
}
