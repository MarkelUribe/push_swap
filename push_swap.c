/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/20 16:37:35 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list *l, char **args)
{
	int	i;

	l->a = malloc(sizeof(t_stack));
	l->b = malloc(sizeof(t_stack));
	if (!l->a || !l->b)
	{
		free_all(l);
		ft_printf("Error\n");
	}
	i = 2;
	l->alen = l->argc - 1;
	l->a->content = ft_atoi(args[1]);
	l->a->index = 0;
	while (i < l->argc)
	{
		
		i++;
	}
}

void	print_ab(t_list *l)
{
	int	i;

	i = 0;
	while (i < l->alen)
	{
		ft_printf("%d\t%d\n", l->a[i], l->b[i]);
		i++;
	}
	ft_printf("_\t_\n");
	ft_printf("A\tB\n");
}

int	main(int argc, char **args)
{
	t_list	*list;

	if (argc == 1)
		return (0);
	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->argc = argc;
	fill_stack(list, args);
	print_ab(list);
	pb(list);
	pb(list);
	pb(list);
	pb(list);
	print_ab(list);
	//rrb(list);
	//print_ab(list);
	free_all(list);
}
