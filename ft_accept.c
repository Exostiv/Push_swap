/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:16:14 by tnicoue           #+#    #+#             */
/*   Updated: 2022/02/02 15:57:30 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pos_accept(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	int value;
    int biggerb;
    int lowerb;

	value = (*stack_a)->content;
	biggerb = ft_bigger_b(stack_b);
    lowerb = ft_lower_b(stack_b);
	printf("Oui\n");
	if (*stack_b == NULL || stock->size_b == 1)
	{
		ft_pb(stack_a, stack_b, stock);
		ft_print_lst(*stack_b);
		if (stock->size_b == 2 && ((*stack_b)->content < (*stack_b)->next->content))
			ft_rb(stack_b);
		return ;
	}
    else if (value > biggerb || value < lowerb)
    {
		printf("koa\n");
		ft_print_lst(*stack_b);
        ft_mvmax(stack_a, stack_b, stock, biggerb);
        return;
    }
	printf("ptn\n");
	ft_pos_accept2(stack_a, stack_b, stock);
}

void ft_pos_accept2(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	int pos_accept;
	t_stack *tmp;
    int value;
	int i;
	
	i = 1;
    value = (*stack_a)->content;
	tmp = (*stack_b);
	while(tmp)
	{
		if(value < tmp->content && value > tmp->next->content)
			pos_accept = i;
		tmp = tmp->next;
		i++;
	}
	ft_pos_accept3(stack_a, stack_b, stock, pos_accept);
}

void ft_pos_accept3(t_stack **a, t_stack **b, t_stock *stock, int pos)
{
	if(pos > (stock->size_b / 2))
	{
		while (pos + 1 < stock->size_b)
		{
			pos++;
			printf("oh crotte\n");
			ft_rrb(b);
        }
	}
	else if (pos < (stock->size_b / 2))
	{
		while (pos > 0)
		{
			pos--;
			printf("oh merde\n");
			ft_rb(b);
		}
	}
	ft_pb(a, b, stock);
}

int ft_bigger_b(t_stack **stack_b)
{
    int check;
    t_stack *tmp;

    tmp = (*stack_b);
    while(tmp)
    {
        check = INT_MIN;
        if (check < tmp->content)
            check = tmp->content;
        tmp = tmp->next;
    }
    return(check);
}

int ft_lower_b(t_stack **stack_b)
{
    int check;
    t_stack *tmp;

    tmp = (*stack_b);
    while(tmp)
    {
        check = INT_MAX;
        if (check > tmp->content)
            check = tmp->content;
        tmp = tmp->next;
    }
    return(check);
}
// 7 5 12  