/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:20:38 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/29 17:20:56 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int nbr)
{
	t_stack	*l;

	l = (t_stack *)malloc(sizeof(t_stack));
	if (!l)
		return (NULL);
	l->nbr = nbr;
	l->next = NULL;
	l->cost = 0;
	l->index = 0;
	return (l);
}

int	stacksize(t_stack *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

t_stack	*stacklast(t_stack *lst)
{
	int	i;

	i = stacksize(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

void	stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = stacklast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

void	stackadd_front(t_stack *lst, t_stack *new)
{
	new->next = lst;
	lst = new;
}
