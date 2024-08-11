/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:28:41 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 04:40:56 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **a)
{
	t_list		*curr;
	t_slist		*tmp;
	t_slist		*tmp_curr;
	int			i;
	int			smallest;

	tmp = lst_cpy(a);
	tmp_curr = tmp;
	i = 0;
	curr = *a;
	while (tmp_curr)
	{
		smallest = find_min_temp(&tmp_curr);
		while (smallest != *(int *)(curr)->content)
			curr = (curr)->next;
		curr->index = i++;
		remove_node(&tmp, smallest);
		tmp_curr = tmp;
		curr = *a;
	}
}

t_slist	*lst_cpy(t_list **a)
{
	t_slist	*tmp;
	t_list	*curr;
	t_slist	*tmp_curr;

	curr = *a;
	tmp = NULL;
	tmp = malloc(sizeof(t_slist));
	tmp_curr = tmp;
	while (curr)
	{
		tmp_curr->content = *(int *)(curr)->content;
		if (curr->next)
			tmp_curr->next = malloc(sizeof(t_slist));
		else
			tmp_curr->next = NULL;
		curr = curr->next;
		tmp_curr = tmp_curr->next;
	}
	return (tmp);
}

void	set_binary(t_list **a)
{
	t_list	*curr;

	curr = *a;
	while (curr)
	{
		curr->binary = (curr->index) >> 2;
		curr = curr->next;
	}
}
