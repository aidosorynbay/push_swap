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
		if (str[i] == '+' || str[i] == '-')
		{
			if (!ft_isdigit(str[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_duplicates_range(char *str)
{

}

int	main(int argc, char *argv[])
{
	int	i;
	int	check_status;
	int	check_range_dup;

	i = 1;
	check_status = 0;
	check_range_dup = 0;
	while (i < argc)
	{
		check_status = check_for_parse(argv[i]);
		if (check_status == 1)
			return (ft_printf("Error\n"), 0);
		check_range_dup = check_duplicates_range(argv[i]);
		if (check_range_dup == 1)
			return (ft_printf("Error\n"), 0);
	}

	ft_printf("success\n");
}