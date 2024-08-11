/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:21:53 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 05:04:43 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **a, t_list **b)
{
	t_list	*curr_a;
    int		i;
	int		int_bits;

    set_index(a);
    set_binary(a);
	int_bits = sizeof(int);
    while (!is_sorted(a) && i < int_bits)
	{
        curr_a = *a;
        while (curr_a)
        {
            if ((curr_a->binary & (1 << i)) == 0)
                pb(a, b);
            else if ((curr_a->binary & (1 << i)) == 1 && still_left(a, &i))
                ra(a);
			else
				break;
            curr_a = *a;
        }
        while (*b)
            pa(a, b);
		i++;
	}
}

bool	still_left(t_list **a, int *i)
{
	t_list	*curr;

	curr = *a;
	while (curr)
	{
		if ((curr->binary & (1 << *i)) == 0)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
