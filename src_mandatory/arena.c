/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:00:45 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/25 17:50:36 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_arena	arena_create(size_t size)
{
	struct s_arena	arena;

	arena.data = malloc(size);
	arena.size = size;
	arena.used = 0;
	return (arena);
}

void	*arena_alloc(struct s_arena *arena, size_t size)
{
	void	*ptr;

	if (arena->used + size > arena->size)
		return (NULL);
	ptr = arena->data + arena->used;
	arena->used = arena->used + size;
	return (ptr);
}

void	arena_free(struct s_arena *arena)
{
	free(arena->data);
}
