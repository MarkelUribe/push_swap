/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:11:05 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/15 13:08:25 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct t_stack
{
	int		*a;
	int		*b;
	int		alen;
	int		blen;
	int		argc;
}	t_stack;

void	sa(int *a);
void	sb(int *b);
void	ss(t_stack *l);
void	pa(t_stack *l);
void	pb(t_stack *l);
void	swap(int *a1, int *a2);
void	ra(t_stack *l);
void	rb(t_stack *l);
void	rr(t_stack *l);
void	rra(t_stack *l);
void	rrb(t_stack *l);
void	rrr(t_stack *l);
void	free_all(t_stack *l);
#endif