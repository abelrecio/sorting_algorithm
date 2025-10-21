/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrecio- <abrecio-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:06:45 by abrecio-          #+#    #+#             */
/*   Updated: 2025/10/21 01:06:46 by abrecio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct			s_arena
{
	char		*data;
	size_t		size;
	size_t		used;
};

typedef struct s_cost
{
	int			pos_b;
	int			pos_a;
	int			ra_moves;
	int			rra_moves;
	int			rb_moves;
	int			rrb_moves;
	int			total;
	int			strategy;
}				t_cost;

typedef struct s_process_data
{
	int			index;
	int			max_index;
	int			*rotations;
}				t_process_data;

struct s_arena	arena_create(size_t size);
void			*arena_alloc(struct s_arena *arena, size_t size);
void			arena_free(struct s_arena *arena);
void			print_stack(t_list *stack, char *name);

// Operaciones básicas
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_a, t_list **stack_b);
void			rra(t_list **stack_a);
void			rrb(t_list **stack_b);
void			rrr(t_list **stack_a, t_list **stack_b);
void			ra(t_list **stack_a);
void			rb(t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b);
void			sa(t_list **stack_a);
void			sb(t_list **stack_b);
void			ss(t_list **stack_a, t_list **stack_b);

// Utilidades
char			**arena_split(char const *s, char c, struct s_arena *arena);
int				get_value(t_list *node);
int				get_max(t_list *stack);
int				get_min(t_list *stack);
int				is_sorted(t_list *stack);
int				find_position(t_list *stack, int val);
int				get_index(t_list *stack, int val);
int				parse_arguments(int argc, char *argv[], struct s_arena *arena,
					t_list **stack_a);

// Greedy sort y funciones auxiliares
void			greedy_sort(t_list **a, t_list **b);
void			sort_three(t_list **stack_a);
int				find_target_pos_in_a(t_list *stack_a, int val_b);
t_cost			calculate_cost(t_list *stack_a, t_list *stack_b, int pos_b);
t_cost			find_cheapest(t_list *stack_a, t_list *stack_b);
void			execute_rr(t_list **stack_a, t_list **stack_b, t_cost cost);
void			execute_rrr(t_list **stack_a, t_list **stack_b, t_cost cost);
void			execute_mixed(t_list **stack_a, t_list **stack_b, t_cost cost,
					int strategy);
void			move(t_list **stack_a, t_list **stack_b, t_cost cost);
void			rotate_to_min(t_list **a);
int				is_sorted(t_list *stack);
void			push_to_b_by_ranges(t_list **a, t_list **b);
long			ft_atol(char *str);
int				count_new_arg(char *nums);
t_cost			calculate_cost(t_list *stack_a, t_list *stack_b, int pos_b);
void			find_best_strategy(t_cost *cost);

#endif
