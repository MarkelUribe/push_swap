/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:09:41 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 19:52:33 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps *l)
{
	if (!l->a->content)
		return ;
	if (!l->b)
	{
		l->b = l->a;
		l->a->next = NULL;
	}
	else
		l->a->next = l->b;
	write(1, "pb\n", 3);
}
