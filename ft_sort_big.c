/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:55:26 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/03 10:47:12 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tribig(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	int	verif;
	int	verif2;

	verif2 = stock->size_a;
	while (stock->done < verif2)
	{
		if (verif2 - stock->done < stock->chunk_size)
			stock->chunk_size = verif2 - stock->done;
		verif = 0;
		ft_prep(stack_a, stack_b, stock);
		if (stock->done > 0)
			ft_mvoldbig(stack_a, stock);
		while (stock->size_b)
		{
			ft_pa(stack_a, stack_b, stock);
			verif++;
		}
		while (verif > 0)
		{
			ft_ra(stack_a);
			verif--;
		}
		stock->done += stock->chunk_size;
		stock->oldbig = stock->bc;
	}
}

void	ft_mvoldbig(t_stack**stack_a, t_stock *stock)
{
	int		i;
	int		pos;
	t_stack	*tmp;

	i = 0;
	pos = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->content == stock->oldbig)
			pos = i;
		tmp = tmp->next;
		i++;
	}
	if (pos > stock->size_a / 2)
	{
		while (pos++ < stock->size_a - 1)
			ft_rra(stack_a);
	}
	else if (pos <= stock->size_a / 2)
	{
		while (pos-- > -1)
			ft_ra(stack_a);
	}
}

void	ft_chunk(t_stock *stock, t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		y;
	t_stack	*tmp;
	int		pos;

	y = -1;
	while (stock->chunk_size > ++y)
	{
		pos = INT_MAX;
		stock->pos2 = INT_MIN;
		tmp = (*stack_a);
		i = 0;
		while (tmp)
		{
			if (tmp->content <= stock->bc && i <= stock->size_a / 2
				&& i < pos && tmp->content > stock->oldbig)
				pos = i;
			else if (i > stock->size_a / 2 && tmp->content <= stock->bc
				&& i > stock->pos2 && tmp->content > stock->oldbig)
				stock->pos2 = i;
			tmp = tmp->next;
			i++;
		}
		ft_mvfirst(stock, pos, stack_a, stack_b);
	}
}

void	ft_mvfirst(t_stock *stock, int pos, t_stack **a, t_stack **b)
{
	stock->pos2 = stock->size_a - stock->pos2;
	if (pos == INT_MAX)
	{
		if (stock->pos2 > 0)
			while (stock->pos2-- > 0)
				ft_rra(a);
	}
	else if (stock->pos2 == stock->size_a - INT_MIN)
	{
		if (pos != INT_MAX)
			ft_m(pos, ft_ra, a);
	}
	else if (pos < stock->pos2)
	{
		ft_m(pos, ft_ra, a);
	}
	else if (stock->pos2 < pos)
	{
		while (stock->pos2-- > 0)
			ft_rra(a);
	}
	else if (pos > stock->pos2 && pos > 0)
		ft_m(pos, ft_ra, a);
	ft_checkb(b, stock);
	ft_pos_accept(a, b, stock);
}

int	ft_checkpos(int check, t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;
	int		pos;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->content == check)
			pos = i;
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

/*void	ft_mvfirst(t_stock *stock, int pos, t_stack **a, t_stack **b)
{
	stock->pos2 = stock->size_a - stock->pos2;
	if (pos == INT_MAX)
	{
		if (stock->pos2 > 0)
		{
			while (stock->pos2 > 0)
			{
				ft_rra(a);
				stock->pos2--;
			}
		}	
	}
	else if (stock->pos2 == stock->size_a - INT_MIN)
	{
		if (pos != INT_MAX)
		{
			while (pos > 0)
			{
				ft_ra(a);
				pos--;
			}
		}
	}
	else if (pos < stock->pos2)
	{
		while (pos > 0)
		{
			ft_ra(a);
			pos--;
		}
	}
	else if (stock->pos2 < pos)
	{
		while (stock->pos2 > 0)
		{
			ft_rra(a);
			stock->pos2--;
		}
	}
	else if (pos > stock->pos2 && pos > 0)
	{
		while (pos)
		{
			ft_ra(a);
			pos--;
		}
	}
	ft_pos_accept(a, b, stock);
}*/