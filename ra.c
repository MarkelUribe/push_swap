/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:10:17 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/14 13:51:23 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(l_stack *l)
{
	int	i;

	i = 0;
	while (i + 1 < l->alen)
	{
		swap(&l->a[i], &l->a[i + 1]);
		i++;
	}
	write(1, "ra\n", 3);
}