/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_eleven_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:20:08 by clora-ro          #+#    #+#             */
/*   Updated: 2022/02/21 10:06:23 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_chunk_eleven(t_stack st, int count)
{
	int	i;
	int	j;

	i = stack_lenght(st);
	j = stack_lenght(st);
	if (count == 2)
	{
		i = 10 * (i / 11);
		i = j - i;
	}
	else
		i = i / 11;
	return (i);
}

int	*altern_chunk_a(t_stack *st, int *chunk, int count)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	len = stack_lenght(*st);
	tab = ft_strcalc(*st);
	ft_sort_int_tab(tab, len);
	while (i < count_chunk_eleven(*st, 2))
	{
		chunk[i] = tab[i + (count_chunk_eleven(*st, 1) * (12 - count))];
		i++;
	}
	free (tab);
	return (chunk);
}

int	*altern_chunk_b(t_stack *st, int *chunk, int count, int v)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	len = stack_lenght(*st);
	tab = ft_strcalc(*st);
	ft_sort_int_tab(tab, len);
	while (i < count_chunk_eleven(*st, count))
	{
		chunk[i] = tab[i + (count_chunk_eleven(*st, count) * (12 - count + v))];
		i++;
	}
	free (tab);
	return (chunk);
}

int	*altern_chunk_c(t_stack *st, int *chunk, int count, int v)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	len = stack_lenght(*st);
	tab = ft_strcalc(*st);
	ft_sort_int_tab(tab, len);
	while (i < count_chunk_eleven(*st, count))
	{
		chunk[i] = tab[i + (count_chunk_eleven(*st, count) * (count - v - 1))];
		i++;
	}
	free (tab);
	return (chunk);
}

int	*altern_chunk(t_stack *st, int *chunk, int count)
{
	static int	v = 0;

	if (!st || !*st)
		return (NULL);
	if (count == 2)
		chunk = malloc(sizeof(int) * count_chunk_eleven(*st, 2));
	else
		chunk = malloc(sizeof(int) * count_chunk_eleven(*st, count));
	if (!chunk)
		return (NULL);
	if (count == 2)
	{
		altern_chunk_a(st, chunk, count);
		v++;
	}
	else if (count % 2 == 0)
	{
		altern_chunk_b(st, chunk, count, v);
		v++;
	}
	else
		altern_chunk_c(st, chunk, count, v);
	return (chunk);
}
