/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:11:05 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/20 16:20:45 by muribe-l         ###   ########.fr       */
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
	int		content;
	int		index;
	t_stack	*next;
	t_stack	*prev;
} t_stack;

typedef struct t_list
{
	t_stack	*a;
	t_stack	*b;
	int		alen;
	int		blen;
	int		argc;
}	t_list;

void	sa(int *a);
void	sb(int *b);
void	ss(t_list *l);
void	pa(t_list *l);
void	pb(t_list *l);
void	swap(int *a1, int *a2);
void	ra(t_list *l);
void	rb(t_list *l);
void	rr(t_list *l);
void	rra(t_list *l);
void	rrb(t_list *l);
void	rrr(t_list *l);
void	free_all(t_list *l);
#endif