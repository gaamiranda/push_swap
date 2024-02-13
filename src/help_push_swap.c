/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:31:07 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:31:08 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos(t_node *node)
{
	int		i;
	int		middle_pos;

	i = 0;
	if (!node)
		return ;
	middle_pos = stack_size(&node) / 2;
	while (node)
	{
		node->current_pos = i;
		if (i <= middle_pos)
			node->above_middle = true;
		else
			node->above_middle = false;
		node = node->next;
		i++;
	}
}

void	target_node(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*best_match;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value 
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				best_match = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = get_smallest_node(a);
		else
			b->target_node = best_match;
		b = b->next;
	}
}

void	price(t_node *a, t_node *b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(&a);
	size_b = stack_size(&b);
	while (b)
	{
		b->push_price = b->current_pos;
		if (!(b->above_middle))
			b->push_price = size_b - (b->current_pos);
		if (b->target_node->above_middle)
			b->push_price += b->target_node->current_pos;
		else
			b->push_price += size_a - (b->target_node->current_pos);
		b = b->next;
	}
}

void	cheapest_node(t_node *stack)
{
	long	cheapest;
	t_node	*cheap;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < cheapest)
		{
			cheapest = stack->push_price;
			cheap = stack;
		}
		stack = stack->next;
	}
	cheap->cheapest = true;
}

void	nodes_init(t_node *a, t_node *b)
{
	get_pos(a);
	get_pos(b);
	target_node(a, b);
	price(a, b);
	cheapest_node(b);
}
