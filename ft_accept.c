/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:16:14 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/03 10:45:57 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pos_accept(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	stock->value = (*stack_a)->content;
	if (stock->size_b == 0 || stock->size_b == 1)
	{
		ft_pb(stack_a, stack_b, stock);
		if (stock->size_b == 2
			&& (*stack_b)->content < (*stack_b)->next->content)
			ft_rb(stack_b);
		return ;
	}
	else if (stock->value > stock->biggerb || stock->value < stock->lowerb)
	{
		ft_mvmax(stack_a, stack_b, stock, stock->biggerb);
		return ;
	}
	else if (stock->value > (*stack_b)->content && stock->value < stock->lastb)
	{
		ft_pb(stack_a, stack_b, stock);
		return ;
	}
	ft_pos_accept2(stack_a, stack_b, stock);
}

void	ft_pos_accept2(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	int		pos_accept;
	t_stack	*tmp;
	int		value;
	int		i;

	i = 1;
	value = (*stack_a)->content;
	tmp = (*stack_b);
	while (tmp && tmp->next)
	{
		if (value < tmp->content && value > tmp->next->content)
			pos_accept = i;
		tmp = tmp->next;
		i++;
	}
	ft_pos_accept3(stack_a, stack_b, stock, pos_accept);
}

void	ft_pos_accept3(t_stack **a, t_stack **b, t_stock *stock, int pos)
{
	if (pos > (stock->size_b / 2))
	{
		while (pos < stock->size_b)
		{
			ft_rrb(b);
			pos++;
		}
	}
	else if (pos <= (stock->size_b / 2))
	{
		while (pos > 0)
		{
			ft_rb(b);
			pos--;
		}
	}
	ft_pb(a, b, stock);
}

int	ft_bigger_b(t_stack **stack_b)
{
	int		check;
	t_stack	*tmp;

	check = INT_MIN;
	tmp = (*stack_b);
	while (tmp)
	{
		if (check < tmp->content)
			check = tmp->content;
		tmp = tmp->next;
	}
	return (check);
}

int	ft_lower_b(t_stack **stack_b)
{
	int		check;
	t_stack	*tmp;

	check = INT_MAX;
	tmp = (*stack_b);
	while (tmp)
	{
		if (check > tmp->content)
			check = tmp->content;
		tmp = tmp->next;
	}
	return (check);
}
