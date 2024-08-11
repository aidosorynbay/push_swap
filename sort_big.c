/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:21:53 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 11:31:07 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **a, t_list **b)
{
	t_list	*curr_a;
	int		counter;

	set_index(a);
	set_binary(a);
	counter = 1;
	while (!is_sorted(a))
	{
		while (!still_left(a, counter))
		{
			curr_a = *a;
			if (((curr_a->binary >> counter) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
		counter++;
	}
}

bool	still_left(t_list **a, int count)
{
	t_list	*curr;

	curr = *a;
	while (curr)
	{
		if (((curr->binary >> count) & 1) == 0)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
