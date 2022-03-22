/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortchoose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:41:45 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/01 14:56:21 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	direction(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	if (stock->size_a == 2)
		ft_tri2(stack_a);
	else if (stock->size_a == 3)
		ft_tri3(stack_a);
	else if (stock->size_a == 4)
		ft_tri4(stack_a, stack_b, stock);
	else if (stock->size_a == 5)
		ft_tri5(stack_a, stack_b, stock);
	else
	{
		if (stock->size_a >= 5 && stock->size_a <= 100)
			stock->chunk_size = stock->size_a / 4;
		else if (stock->size_a > 100)
			stock->chunk_size = stock->size_a / 9;
		ft_tribig(stack_a, stack_b, stock);
	}
}

void	get_size_a(t_stack **stack_a, t_stock *stock)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	stock->size_a = i;
}
