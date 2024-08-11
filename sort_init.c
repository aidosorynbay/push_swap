/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:29:55 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 04:12:13 by aorynbay         ###   ########.fr       */
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
	int		i;
	t_list	*min;
	t_list	*max;

	i = 0;
	while (i < ft_lstsize(*a))
	{
		min = find_min(a);
		max = find_max(a);
		if (*(int *)(*a)->content == *(int *)min->content
			|| *(int *)(*a)->content == *(int *)max->content)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	sort_three(a);
	if (find_max(b) == *b)
		(pa(a, b), ra(a), pa(a, b));
	else
		(pa(a, b), pa(a, b), ra(a));
}
