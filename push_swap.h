/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:54:40 by aorynbay          #+#    #+#             */
/*   Updated: 2024/08/05 16:54:40 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		ft_strcmp(char *s1, char *s2);
void	skip_whitespace(char *str, int *i);
int		count_digits(char *str, int i);
char	*create_result(char *str, int i, int count);
t_list	*create_node(char *result);

#endif