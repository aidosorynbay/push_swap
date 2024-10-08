/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:54:37 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/05 16:54:37 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_parse(char *str, int count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			&& str[i] != '\0')
		{
			i++;
			count++;
		}
		if (str[i] == '\0')
			break ;
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (1);
		if ((str[i] == '+' || str[i] == '-'))
		{
			if (!ft_isdigit(str[i + 1]) || (i != 0 && str[i - 1] != ' '))
				return (1);
		}
		i++;
	}
	if (str[i] == '\0' && count == i)
		return (1);
	return (0);
}

void	make_list(t_list **begin, char *str)
{
	int		i;
	int		count;
	t_list	*add;
	char	*result;

	i = 0;
	while (str[i] != '\0')
	{
		skip_whitespace(str, &i);
		if (str[i] == '\0')
			break ;
		count = count_digits(str, i);
		if (count == 0 || (count == 1 && (str[i] == '+' || str[i] == '-')))
			return (error_return(begin), (void)0);
		result = create_result(str, i, count);
		if (result == NULL)
			return (error_return(begin), (void)0);
		add = create_node(result);
		if (add == NULL)
			return (write (2, "Error\n", 6), free(result),
				ft_lstclear(begin, &free), (void)0);
		ft_lstadd_back(begin, add);
		i += count;
	}
}

void	check_range(t_list **begin)
{
	t_list	*curr;
	int		result;
	int		checker;
	int		*res_ptr;

	curr = *begin;
	checker = 1;
	while (curr)
	{
		result = ft_atoi(curr->content, &checker);
		if (result == -1 && checker == -1)
			return (error_return(begin), (void)0);
		else
		{
			res_ptr = malloc(sizeof(int));
			if (res_ptr == NULL)
				return (error_return(begin), (void)0);
			*res_ptr = result;
			free(curr->content);
			curr->content = res_ptr;
		}
		curr = curr->next;
	}
}

void	check_dup(t_list **begin)
{
	t_list	*curr;
	t_list	*cmp;
	int		str1;
	int		str2;

	curr = *begin;
	while (curr)
	{
		cmp = curr->next;
		str1 = *(int *)curr->content;
		while (cmp)
		{
			str2 = *(int *)cmp->content;
			if (str1 == str2)
				return (error_return(begin), (void)0);
			cmp = cmp->next;
		}
		curr = curr->next;
	}
}

void	check_parse(int argc, char **argv, t_list **a)
{
	int		i;
	int		check_status;
	int		count;

	i = 1;
	count = 0;
	check_status = 0;
	while (i < argc)
	{
		check_status = check_for_parse(argv[i], count);
		if (check_status == 1)
			return (error_return(a), (void)0);
		make_list(a, argv[i]);
		i++;
	}
	check_range(a);
	check_dup(a);
}
