/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:21:53 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/12 18:29:58 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **a, t_list **b)
{
	t_list	*curr_a;
	int		counter;
	int		max_bit;
	int		list_size;

	set_index(a);
	set_binary(a);
	max_bit = get_max_bits(a);
	counter = 0;
	while (counter < max_bit)
	{
		list_size = ft_lstsize(*a);
		while (list_size--)
		{
			curr_a = *a;
			if (((curr_a->binary >> counter) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			curr_a = curr_a->next;
		}
		while (*b)
			pa(a, b);
		counter++;
	}
}

int get_max_bits(t_list **a)
{
	t_list	*curr;
	int		max_num;
	int		max_bits;

	curr = *a;
	max_num = 0;
	while (curr)
	{
		if (curr->index > max_num)
			max_num = curr->index;
		curr = curr->next;
	}
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
