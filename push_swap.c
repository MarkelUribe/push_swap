/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/23 17:17:45 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(t_ps *l, char **args, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				free_all(l);
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	fill_stack(t_ps *l, char **args, int argc)
{
	int		i;
	t_stack	*tmp;

	check_args(l, args, argc);
	l->a = stacknew(ft_atoi(args[1]));
	l->b = NULL;
	i = 2;
	while (i < argc)
	{
		tmp = stacknew(ft_atoi(args[i]));
		if (!tmp)
		{
			free_all(l);
			ft_printf("Error\n");
			exit(0);
		}
		stacklast(l->a)->next = tmp;
		i++;
	}
}

void	print_ab(t_ps *l)
{
	t_stack	*ta;
	t_stack	*tb;

	ta = l->a;
	tb = l->b;
	while (ta || tb)
	{
		if (ta && tb)
			ft_printf("%d\t%d\n", ta->content, tb->content);
		else if (ta)
			ft_printf("%d\t \n", ta->content);
		else if (tb)
			ft_printf(" \t%d\n", tb->content);
		if (ta)
			ta = ta->next;
		if (tb)
			tb = tb->next;
	}
	ft_printf("_\t_\n");
	ft_printf("A\tB\n");
}

int	main(int argc, char **args)
{
	t_ps	*list;

	list = malloc(sizeof(t_ps));
	if (argc == 1 || !list)
	{
		ft_printf("Error\n");
		return (0);
	}
	fill_stack(list, args, argc);
	print_ab(list);
	pb(list);
	pb(list);
	pb(list);
	pb(list);
	print_ab(list);
	rra(list);
	print_ab(list);
	free_all(list);
	return (1);
}
