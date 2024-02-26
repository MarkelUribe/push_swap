/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:34:50 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/26 16:48:13 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicated(t_ps *l)
{
	int		count;
	t_stack	*tmp;
	t_stack	*current;

	tmp = l->a;
	while (tmp)
	{
		count = 0;
		current = tmp;
		while (current != NULL)
		{
			if (tmp->content == current->content)
				count++;
			current = current->next;
		}
		if (count >= 2)
		{
			free_all(l);
			ft_printf("Error\n");
			exit(0);
		}
		tmp = tmp->next;
	}
}

void	check_args(t_ps *l, char **args, int argc)
{
	int		i;
	int		j;
	long	cmp;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(args[i], ' ');
		cmp = ft_atol(args[i]);
		j = 0;
		while (args[i][j])
		{
			if ((!ft_isdigit(args[i][j]) && args[i][j] != '-')
				|| cmp > INT_MAX || cmp < INT_MIN)
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
	check_duplicated(l);
}