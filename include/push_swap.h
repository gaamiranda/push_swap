/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:22:25 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:22:38 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				current_pos;
	int				push_price;
	bool			above_middle;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*target_node;
}	t_node;

char	**ft_split(char *str, char c);
void	rra(t_node **a, int control);
void	rrb(t_node **b, int control);
void	rrr(t_node **a, t_node **b, int control);
void	ra(t_node **a, int control);
void	rb(t_node **b, int control);
void	rr(t_node **a, t_node **b, int control);
void	sa(t_node **a, int control);
void	sb(t_node **b, int control);
void	pa(t_node **a, t_node **b, int control);
void	pb(t_node **a, t_node **b, int control);
int		list_sorted(t_node **stack);
void	stack_init(t_node **stack, char **ptr);
int		stack_size(t_node **stack);
void	mini_sort(t_node **stack);
long	ft_atol(char *str);
int		ft_check_atol(char *str);
int		ft_check_duplicates(long num, int index, char **str);
int		ft_check_argv(char **ptr);
void	ft_free(t_node **stack);
void	ft_free_args(char **args);
void	push_swap(t_node **a, t_node **b);
void	init_stackb(t_node **a, t_node **b);
void	get_pos(t_node *node);
void	nodes_init(t_node *a, t_node *b);
t_node	*get_highest(t_node *stack);
t_node	*get_lowest(t_node *stack);
void	price(t_node *a, t_node *b);
void	cheapest_node(t_node *stack);
void	push_nodes(t_node **a, t_node **b);
void	rotate(t_node **a, t_node **b, t_node *cheapest);
void	reverse_rotate(t_node **a, t_node **b, t_node *cheapest);
void	push_final(t_node **stack, t_node *top, char c);
void	swap(t_node **stack);
void	rrrotate(t_node **stack);
void	reverse_rot(t_node **stack);
t_node	*get_smallest_node(t_node *stack);
void	ss(t_node **a, t_node **b, int control);

#endif
