/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:50:20 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 04:15:42 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list **a)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *a;
	max = tmp;
	while (tmp)
	{
		if (*(int *)tmp->content > *(int *)max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*find_min(t_list **a)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *a;
	min = tmp;
	while (tmp)
	{
		if (*(int *)tmp->content < *(int *)min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	find_min_temp(t_slist **a)
{
	t_slist	*tmp;
	t_slist	*min;

	tmp = *a;
	min = tmp;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min->content);
}

void	remove_node(t_slist **a, int smallest)
{
	t_slist	*tmp;
	t_slist	*prev;

	tmp = *a;
	prev = NULL;
	while (tmp)
	{
		if (tmp->content == smallest)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*a = tmp->next;
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
