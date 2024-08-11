/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:29:55 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 05:53:05 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_init(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	if (ft_lstsize(*a) == 2)
	{
		if (*(int *)tmp->content > *(int *)((tmp->next)->content))
			sa(a);
	}
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}

bool	is_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)(tmp->next)->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three(t_list **a)
{
	t_list	*highest_node;

	highest_node = find_max(a);
	if (*(int *)(*a)->content == *(int *)highest_node->content)
		ra(a);
	else if (*(int *)(*a)->next->content == *(int *)highest_node->content)
		rra(a);
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a);
}

void	sort_four(t_list **a, t_list **b)
{
	t_list	*min;

	min = find_min(a);
	while (*(int *)(*a)->content != *(int *)min->content)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	t_list	*min;

	min = find_min(a);
	while (*(int *)(*a)->content != *(int *)min->content)
		ra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
