/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:28:12 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/06 16:22:32 by muribe-l         ###   ########.fr       */
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

void	rrb(t_ps *l)
{
	t_stack	*lst;
	t_stack	*last;

	if (!l->b || !l->b->next)
		return ;
	last = stacklast(l->b);
	lst = l->b;
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
	last->next = l->b;
	l->b = last;
	write(1, "rrb\n", 4);
}
