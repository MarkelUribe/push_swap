/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/15 12:57:38 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *l, char **args)
{
	int	i;

	l->a = (int *)malloc(sizeof(int) * l->argc - 1);
	l->b = (int *)malloc(sizeof(int) * l->argc - 1);
	if (!l->a || !l->b)
		free_all(l);
	i = 0;
	while (i < l->argc - 1)
	{
		l->a[i] = ft_atoi(args[0]);
		i++;
	}
}

int	main(int argc, char **args)
{
	t_stack	*list;

	if (argc == 1)
		return (0);
	list = malloc(sizeof(t_stack));
	if (!list)
		return (0);
	list->argc = argc;
	fill_stack(list, args);
}
