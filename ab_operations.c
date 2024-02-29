/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:28:06 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/29 12:31:12 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_ps *l)
{
	ra(l);
	rb(l);
	write(1, "rr\n", 3);
}

void	rrr(t_ps *l)
{
	rra(l);
	rrb(l);
	write(1, "rrr\n", 4);
}

void	ss(t_ps *l)
{
	sa(l);
	sb(l);
	write(1, "ss\n", 3);
}

void	swap(t_stack *a1, t_stack *a2)
{
	t_stack	*temp;

	temp = a1->next;
	a1->next = a2->next;
	a2->next = temp;
}
