/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/21 20:42:12 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_ps *l, char **args, int argc)
{
	int		i;
	t_stack	*tmp;

	l->a = stacknew(ft_atoi(args[1]));
	l->b = NULL;
	if (!l->a)
	{
		free_all(l);
		ft_printf("Error\n");
	}
	i = 2;
	while (i < argc)
	{
		tmp = stacknew(ft_atoi(args[i]));
		if (!tmp)
		{
			free_all(l);
			ft_printf("Error\n");
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
	while (ta && tb)
	{
		ta = l->a->next;
		tb = l->b->next;
		ft_printf("%d\t%d\n", ta->content, tb->content);
		ta = ta->next;
		tb = tb->next;
	}
	ft_printf("_\t_\n");
	ft_printf("A\tB\n");
}

int	main(int argc, char **args)
{
	t_ps	*list;

	if (argc == 1)
		return (0);
	list = malloc(sizeof(t_ps));
	if (!list)
		return (0);
	fill_stack(list, args, argc);
	print_ab(list);
	//pb(list);
	//pb(list);
	//pb(list);
	//pb(list);
	//print_ab(list);
	//rrb(list);
	//print_ab(list);
	free_all(list);
}
