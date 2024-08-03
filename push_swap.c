#include "push_swap.h"

int	check_for_parse(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (1);
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (1);
		if ((str[i] == '+' || str[i] == '-') && (i == 0 || str[i - 1] == ' '))
		{
			if (!ft_isdigit(str[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

void	make_list(t_list **begin, char *str)
{
	int		i;
	int		j;
	int		count;
	t_list	*add;
	char	*result;

	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		count = 0;
		while ((ft_isdigit(str[i + count]) || str[i + count] == '+' || str[i + count] == '-') && str[i + count] != '\0')
			count++;
		if (count == 0)
			i++;
		result = malloc(sizeof(char) * (count + 1));
		if (result == NULL)
			return (ft_lstclear(begin, &free), (void)0);
		j = 0;
		while ((ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-') && j < count)
		{
			result[j] = str[i + j];
			j++;
		}
		result[count] = '\0';
		add = malloc(sizeof(t_list));
		if (add == NULL)
			return (free(result), ft_lstclear(begin, &free), (void)0);
		add->content = result;
		add->next = NULL;
		ft_lstadd_back(begin, add);
		i += count;
	}
}

void	check_range(t_list **begin)
{
	t_list	*curr;
	int		result;
	int		checker;

	curr = *begin;
	checker = 1;
	while (curr)
	{
		result = ft_atoi(curr->content, &checker);
		if (result == -1 && checker == -1)
			ft_lstclear(begin, &free);
		else
		{
			int	*res_ptr = malloc(sizeof(int));
			if (res_ptr == NULL)
				return (ft_lstclear(begin, &free), (void)0);
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
	char	*str1;
	char	*str2;
	
	curr = *begin;
	while (curr)
	{
		cmp = curr->next;
		str1 = (char *)curr->content;
		while (cmp)
		{
			str2 = (char *)cmp->content;
			if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
				return (ft_lstclear(begin, &free), (void)0);
			cmp = cmp->next;
		}
		curr = curr->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*head;
	t_list	*curr;
	int		i;
	int		check_status;

	i = 1;
	head = malloc(sizeof(t_list));
	head = NULL;
	check_status = 0;
	while (i < argc)
	{
		check_status = check_for_parse(argv[i]);
		if (check_status == 1)
			return (ft_printf("Error\n"), 0);
		make_list(&head, argv[i]);
		i++;
	}
	check_range(&head);
	check_dup(&head);
	curr = head;
	while (curr)
	{
		ft_printf("|%i|\n", *(int*)curr->content);
		curr = curr->next;
	}
	ft_lstclear(&head, &free);
}