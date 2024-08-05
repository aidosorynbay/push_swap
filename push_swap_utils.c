/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:54:33 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/05 17:53:15 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	skip_whitespace(char *str, int *i)
{
	while ((str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		&& str[*i] != '\0')
		(*i)++;
}

int	count_digits(char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == '+' || str[i] == '-')
		count++;
	while (ft_isdigit(str[i + count]))
		count++;
	return (count);
}

char	*create_result(char *str, int i, int count)
{
	char	*result;
	int		j;

	result = malloc(sizeof(char) * (count + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < count)
	{
		result[j] = str[i + j];
		j++;
	}
	result[count] = '\0';
	return (result);
}

t_list	*create_node(char *result)
{
	t_list	*add;

	add = malloc(sizeof(t_list));
	if (add == NULL)
		return (NULL);
	add->content = result;
	add->next = NULL;
	return (add);
}
