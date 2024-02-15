/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:07:02 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/15 12:57:38 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *l)
{
	if (l->a)
		free(l->a);
	if (l->b)
		free(l->b);
	if (l)
		free(l);
	ft_printf("Error\n");
}
