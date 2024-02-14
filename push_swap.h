/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:11:05 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/14 13:52:12 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

typedef struct l_stack
{
	int		*a;
	int		*b;
	int		alen;
	int		blen;
	int		argc;
}	l_stack;

void	sa(int *a);
void	sb(int *b);
void	ss(l_stack *l);
void	pa(l_stack *l);
void	pb(l_stack *l);
void	swap(int *a1, int *a2);
void	ra(l_stack *l);
void	rb(l_stack *l);
#endif