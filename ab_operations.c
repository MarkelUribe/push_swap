/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:28:06 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/07 13:13:44 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_ps *l)
{
	t_stack	*tmp;

	if (l->a != NULL && l->a->next != NULL)
	{
		tmp = l->a;
		l->a = l->a->next;
		tmp->next = NULL;
		stacklast(l->a)->next = tmp;
	}
	if (l->b != NULL && l->b->next != NULL)
	{
		tmp = l->b;
		l->b = l->b->next;
		tmp->next = NULL;
		stacklast(l->b)->next = tmp;
	}
	write(1, "rr\n", 3);
}

static int	fake_rra(t_ps *l)
{
	t_stack	*lst;
	t_stack	*last;

	if (!l->a || !l->a->next)
		return (0);
	last = stacklast(l->a);
	lst = l->a;
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
	last->next = l->a;
	l->a = last;
	return (1);
}

static int	fake_rrb(t_ps *l)
{
	t_stack	*lst;
	t_stack	*last;

	if (!l->b || !l->b->next)
		return (0);
	last = stacklast(l->b);
	lst = l->b;
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
	last->next = l->b;
	l->b = last;
	return (1);
}

void	rrr(t_ps *l)
{
	if (fake_rra(l) || fake_rrb(l))
		write(1, "rrr\n", 4);
}

void	ss(t_ps *l)
{
	t_stack	*tmp;

	if (l->a != NULL && l->a->next != NULL
		&& l->b != NULL && l->b->next != NULL)
	{
		tmp = l->a->next;
		l->a->next = tmp->next;
		tmp->next = l->a;
		l->a = tmp;
		tmp = l->b->next;
		l->b->next = tmp->next;
		tmp->next = l->b;
		l->b = tmp;
		write(1, "ss\n", 3);
	}
}
