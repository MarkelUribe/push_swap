/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/19 16:05:44 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ab(t_ps *l)
{
	t_stack	*ta;
	t_stack	*tb;
	int		count;

	count = 1;
	ta = l->a;
	tb = l->b;
	while (ta || tb)
	{
		if (ta && tb)
			ft_printf("%d-\t%d\t%d\n", ta->cost, ta->nbr, tb->nbr);
		else if (ta)
			ft_printf("%d-\t%d\t \n", ta->cost, ta->nbr);
		else if (tb)
			ft_printf("%d-\t \t%d\n", tb->cost, tb->nbr);
		if (ta)
			ta = ta->next;
		if (tb)
			tb = tb->next;
		count++;
	}
	ft_printf("\t_\t_\n");
	ft_printf("\tA\tB\n");
}

int	main(int argc, char **args)
{
	t_ps	*list;

	if (argc == 1)
		return (0);
	list = malloc(sizeof(t_ps));
	if (!list)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	fill_stack(list, args, argc);
	apply_index(list);
	turk_sort(list);
	free_all(list);
	return (1);
}
