/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:34:50 by muribe-l          #+#    #+#             */
/*   Updated: 2024/03/19 14:16:00 by muribe-l         ###   ########.fr       */
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
			if (tmp->nbr == current->nbr)
				count++;
			current = current->next;
		}
		if (count >= 2)
			error_free(l);
		tmp = tmp->next;
	}
}

void	add_to_stack(t_ps *l, char *arg, char **args)
{
	t_stack	*tmp;

	tmp = stacknew(ft_atoi(arg));
	if (!tmp)
	{
		free_split(args);
		error_free(l);
	}
	if (!l->a)
		l->a = tmp;
	else
		stacklast(l->a)->next = tmp;
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

void	check_args(t_ps *l, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
		{
			free_split(args);
			error_free(l);
		}
		add_to_stack(l, args[i], args);
		i++;
	}
}

void	fill_stack(t_ps *l, char **args, int argc)
{
	int		i;
	char	**split;

	l->a = NULL;
	l->b = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(args[i], ' ');
		check_args(l, split);
		free_split(split);
		i++;
	}
	check_duplicated(l);
}
