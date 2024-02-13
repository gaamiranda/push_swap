/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:35:49 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:35:50 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stackb(t_node **a, t_node **b)
{
	while (stack_size(a) > 3 && !(list_sorted(a)))
		pb(a, b, 1);
}

void	rotate(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b, 1);
	get_pos(*a);
	get_pos(*b);
}

void	reverse_rotate(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, 1);
	get_pos(*a);
	get_pos(*b);
}

void	push_final(t_node **stack, t_node *top, char c)
{
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->above_middle)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (c == 'b')
		{
			if (top->above_middle)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	push_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_lowest(*b);
	if (cheapest_node->above_middle 
		&& cheapest_node->target_node->above_middle)
		rotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle) 
		&& !(cheapest_node->target_node->above_middle))
		reverse_rotate(a, b, cheapest_node);
	push_final(b, cheapest_node, 'b');
	push_final(a, cheapest_node->target_node, 'a');
	pa(a, b, 1);
}
