/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/19 13:41:37 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *l, char **args)
{
	int	i;

	l->a = (int *)malloc(sizeof(int) * l->argc - 1);
	l->b = (int *)malloc(sizeof(int) * l->argc - 1);
	if (!l->a || !l->b)
	{
		free_all(l);
		ft_printf("Error\n");
	}
	i = 1;
	l->alen = l->argc - 1;
	while (i < l->argc)
	{
		l->a[i - 1] = ft_atoi(args[i]);
		i++;
	}
}

void	print_a(t_stack *l)
{
	int	i;

	i = 0;
	while (i < l->alen)
	{
		ft_printf("%d\n", l->a[i]);
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
	print_a(list);
	free_all(list);
}
