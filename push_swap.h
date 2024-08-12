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
# include <stdbool.h>

typedef struct t_slist
{
	int				content;
	struct t_slist	*next;
}	t_slist;

int			ft_strcmp(char *s1, char *s2);
void		skip_whitespace(char *str, int *i);
int			count_digits(char *str, int i);
char		*create_result(char *str, int i, int count);
t_list		*create_node(char *result);
int			check_for_parse(char *str, int count);
void		make_list(t_list **begin, char *str);
void		check_range(t_list **begin);
void		check_dup(t_list **begin);
void		check_parse(int argc, char **argv, t_list **a);
bool		is_sorted(t_list **a);
void		sort_init(t_list **a, t_list **b);
void		sort_three(t_list **a);
void		sort_four(t_list **a, t_list **b);
void		sort_five(t_list **a, t_list **b);
void		sort_big(t_list **a, t_list **b);
void		set_index(t_list **a);
void		set_binary(t_list **a);
t_slist		*lst_cpy(t_list **a);

void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

t_list		*find_max(t_list **a);
t_list		*find_min(t_list **a);
int			find_min_temp(t_slist **a);
void		remove_node(t_slist **a, int smallest);
void		ft_strcpy(char *s1, char *s2);
int			get_max_bits(t_list **a);
void		error_return(t_list **begin);

#endif