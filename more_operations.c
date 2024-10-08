/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:40:58 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 09:10:05 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = ft_lstlast(*a);
	last->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = ft_lstlast(*b);
	last->next = tmp;
	tmp->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	last = ft_lstlast(*a);
	while (tmp->next != last)
		tmp = tmp->next;
	last->next = *a;
	*a = last;
	tmp->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	last = ft_lstlast(*b);
	while (tmp->next != last)
		tmp = tmp->next;
	last->next = *b;
	*b = last;
	tmp->next = NULL;
	ft_printf("rrb\n");
}
