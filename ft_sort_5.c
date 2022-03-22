/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:44:03 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/01 10:27:05 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	getlower4_5(t_stack **stack_a, t_stock *stock)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (stock->shorter > tmp->content)
		{
			stock->shorter = tmp->content;
			stock->pos_shorter = i;
		}
		tmp = tmp->next;
		i++;
	}
}

void	ft_tri5(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	getbigger(stack_a, stock);
	mvbigger(stack_a, stack_b, stock);
	getlower4_5(stack_a, stock);
	mvlower4(stack_a, stack_b, stock);
	ft_tri3(stack_a);
	ft_pa(stack_a, stack_b, stock);
	ft_pa(stack_a, stack_b, stock);
	ft_ra(stack_a);
}

void	mvbigger(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	int	count;

	count = stock->size_a - stock->pos_bigger;
	if (stock->pos_bigger > 2)
	{
		while (count > 0)
		{
			ft_rra(stack_a);
			count--;
		}
		ft_pb(stack_a, stack_b, stock);
	}
	else
	{
		while (stock->pos_bigger)
		{
			ft_ra(stack_a);
			stock->pos_bigger--;
		}
		ft_pb(stack_a, stack_b, stock);
	}
}

void	mvbigger2(t_stack **stack_b, t_stock *stock)
{
	int	count;

	count = stock->size_b - stock->pos_bigger;
	if (stock->pos_bigger > stock->size_b / 2)
	{
		while (count > 0)
		{
			ft_rrb(stack_b);
			count--;
		}
	}
	else
	{
		while (stock->pos_bigger)
		{
			ft_rb(stack_b);
			stock->pos_bigger--;
		}
	}
}

void	getbigger(t_stack **stack_a, t_stock *stock)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (stock->bigger < tmp->content)
		{
			stock->bigger = tmp->content;
			stock->pos_bigger = i;
		}
		tmp = tmp->next;
		i++;
	}
}
