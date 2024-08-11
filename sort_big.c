/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:21:53 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 10:21:18 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **a, t_list **b)
{
	t_list	*curr_a;
	int		i;
	int		counter;

	set_index(a);
	set_binary(a);
	i = 1;
	counter = 1;
	while (!is_sorted(a))
	{
		while (!still_left(a, i, counter))
		{
			curr_a = *a;
			if ((curr_a->binary & i) >> counter == 0)
				pb(a, b);
			else
				ra(a);
		}
		if (*b)
		{
			while (*b)
				pa(a, b);
		}
		i = i << 1;
		counter++;
	}
}

bool	still_left(t_list **a, int len, int count)
{
	t_list	*curr;
	int		val;

	curr = *a;
	val = 0;
	while (curr)
	{
		val = (curr->binary & len);
		if (val >> count == 0)
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
