/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:58:10 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/11 04:34:41 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*curr;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		return (ft_printf("Error\n"), ft_lstclear(&a, &free),
			ft_lstclear(&b, &free), 0);
	}
	check_parse(argc, argv, &a);
	if (is_sorted(&a) == 1)
		return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), 0);
	sort_init(&a, &b);
	curr = a;
	while (curr)
	{
		ft_printf("%d\n", *(int *)curr->content);
		curr = curr->next;
	}
	return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), 0);
}
