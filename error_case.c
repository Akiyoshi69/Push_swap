/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:10:01 by clora-ro          #+#    #+#             */
/*   Updated: 2022/04/20 16:25:08 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	return_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(0);
}

char	**check_join(int count, char **str)
{
	int		i;
	char	*temp;
	char	**str_b;

	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	i = 1;
	if (count > 1)
	{
		while (str[i])
		{
			temp = ft_strjoin_free(temp, str[i]);
			temp = ft_strjoin_free(temp, " ");
			i++;
		}
		str_b = ft_split(temp, ' ');
		free (temp);
	}
	else
		str_b = ft_split(str[i], ' ');
	return (str_b);
}

int	check_double(t_stack st)
{
	int	*tab;
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	tab = ft_strcalc(st);
	count = count_stack(st);
	while (j < count - 1)
	{
		i = 0;
		while (i < count)
		{
			if (i == j)
				i++;
			if (st->value == tab[i])
				return (free_tab_stack(tab, st));
			i++;
		}
		st = st->next;
		j++;
	}
	free(tab);
	return (1);
}

int	check_count(int count, t_stack st)
{
	t_stack	temp;

	temp = st;
	if (count == 0 || count == 1)
		return (0);
	if (check_double(temp) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}

long int	check_atoi(const char *str)
{
	long int	min;
	long int	max;

	min = -2147483648;
	max = 2147483647;
	if (ft_atoi(str) > max || ft_atoi(str) < min)
		return_error();
	return (ft_atoi(str));
}
