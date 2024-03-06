/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:28:09 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/06 16:21:55 by muribe-l         ###   ########.fr       */
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

void	ra(t_ps *l)
{
	t_stack	*d;

	if (l->a != NULL && l->a->next != NULL)
	{
		d = l->a;
		l->a = l->a->next;
		d->next = NULL;
		stacklast(l->a)->next = d;
		write(1, "ra\n", 3);
	}
}

void	rra(t_ps *l)
{
	t_stack	*lst;
	t_stack	*last;

	if (!l->a || !l->a->next)
		return ;
	last = stacklast(l->a);
	lst = l->a;
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
	last->next = l->a;
	l->a = last;
	write(1, "rra\n", 4);
}
