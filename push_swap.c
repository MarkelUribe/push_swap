/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/14 19:26:23 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	fill_stack(l_stack *l, char **args)
{

}

int	main(int argc, char **args)
{
	l_stack	*list;

	if (argc == 1)
		return (0);
	list = malloc(sizeof(l_stack));
	if (!list)
		return (0);
	list->argc = argc;
	
}