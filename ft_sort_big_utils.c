/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:09:19 by tnicoue           #+#    #+#             */
/*   Updated: 2022/03/01 16:37:34 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_biggerchunk_a(t_stack **stack_a, t_stock *stock)
{
	int		check;
	t_stack	*tmp;
	int		*tab;
	int		i;

	i = -1;
	tab = malloc(sizeof(int) * stock->chunk_size);
	while (stock->chunk_size > ++i)
		tab[i] = INT_MAX;
	i = 0;
	while (stock->chunk_size > i)
	{
		tmp = (*stack_a);
		check = INT_MAX;
		while (tmp)
		{
			if (check > tmp->content && tmp->content > stock->oldbig
				&& ft_checktab(tmp->content, tab, stock->chunk_size) != 0)
				check = tmp->content;
			tmp = tmp->next;
		}
		tab[i++] = check;
	}
	stock->bc = tab[i - 1];
	free(tab);
}

int	ft_checktab(int valeur, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == valeur)
			return (0);
		i++;
	}
	return (1);
}
