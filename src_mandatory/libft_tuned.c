/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tuned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:33:06 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/13 12:48:55 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	is_sep(char c, char sep)
{
	return (c == sep);
}

static int	word_counter(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !is_sep(s[i], c))
				i++;
		}
	}
	return (count);
}

static char	*dup_word(const char *s, char c, int *i, struct s_arena *arena)
{
	int		start;
	int		len;
	char	*word;

	start = *i;
	len = 0;
	while (s[*i] && !is_sep(s[*i], c))
	{
		(*i)++;
		len++;
	}
	word = arena_alloc(arena, len + 1);
	if (!word)
		return (NULL);
	len = 0;
	while (start < *i)
		word[len++] = s[start++];
	word[len] = '\0';
	return (word);
}

char	**arena_split(char const *s, char c, struct s_arena *arena)
{
	char	**arr;
	int		i;
	int		idx;

	i = 0;
	idx = 1;
	if (!s)
		return (NULL);
	arr = arena_alloc(arena, sizeof(char *) * (word_counter(s, c) + 2));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i])
		{
			arr[idx] = dup_word(s, c, &i, arena);
			if (!arr[idx++])
				return (NULL);
		}
	}
	arr[idx] = NULL;
	return (arr);
}
