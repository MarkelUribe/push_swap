/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:07:02 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 18:25:54 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_stack	*tmp;

	if (!s || !&s)
		return ;
	while (s && &s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
	}
}

void	free_all(t_ps *l)
{
	if (l->a)
		free_stack(l->a);
	if (l->b)
		free_stack(l->b);
	if (l)
		free(l);
}
