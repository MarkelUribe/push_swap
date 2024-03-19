/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:07:02 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/19 14:08:53 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
	}
}

void	free_all(t_ps *l)
{
	if (l->a)
		free_stack(l->a);
	if (l->b)
		free_stack(l->b);
	if (l)
		free(l);
}

void	error_free(t_ps *l)
{
	free_all(l);
	write(2, "Error\n", 6);
	exit(0);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
