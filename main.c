/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:58:10 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/12 18:39:02 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		return (ft_printf("Error\n"), ft_lstclear(&a, &free),
			ft_lstclear(&b, &free), 0);
	}
	check_parse(argc, argv, &a);
	if (a == NULL)
		return (0);
	sort_init(&a, &b);
	return (ft_lstclear(&a, &free), ft_lstclear(&b, &free), 0);
}
