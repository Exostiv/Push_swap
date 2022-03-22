/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:34:26 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/03 10:41:51 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mvmax(t_stack **a, t_stack **b, t_stock *stock, int max)
{
	t_stack	*tmp;
	int		i;

	tmp = (*b);
	i = 0;
	while (tmp)
	{
		if (tmp->content == max)
			stock->pos = i;
		tmp = tmp->next;
		i++;
	}
	ft_rotate_max(a, b, stock, max);
}

void	ft_rotate_max(t_stack **a, t_stack **b, t_stock *stock, int max)
{
	if (stock->pos > (stock->size_b / 2) + 1)
	{
		while (stock->pos < stock->size_b)
		{
			stock->pos++;
			ft_rrb(b);
		}
	}
	else if (stock->pos <= (stock->size_b / 2) + 1)
	{
		while (stock->pos > 0)
		{
			stock->pos--;
			ft_rb(b);
		}
	}
	ft_pb(a, b, stock);
	if ((*b)->content < max)
		ft_rb(b);
}

int	ft_lastb(t_stack **stack_b)
{
	int		check;
	t_stack	*tmp;

	tmp = (*stack_b);
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	check = tmp->content;
	return (check);
}

void	ft_prep(t_stack**stack_a, t_stack**stack_b, t_stock*stock)
{
	ft_biggerchunk_a(stack_a, stock);
	ft_chunk(stock, stack_a, stack_b);
	getbigger(stack_b, stock);
	mvbigger2(stack_b, stock);
}

int	checkcp(int i, t_stock *stock)
{
	if (i > stock->size_a / 2)
		i = i - stock->size_a / 2;
	return (i);
}
