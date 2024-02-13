/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_highest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:30:14 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:30:15 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_highest(t_node *stack)
{
	t_node	*highest_value;
	int		val;

	val = INT_MIN;
	while (stack)
	{
		if (stack->value > val)
		{
			val = stack->value;
			highest_value = stack;
		}
		stack = stack->next;
	}
	return (highest_value);
}

t_node	*get_lowest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*get_smallest_node(t_node *stack)
{
	long	smallest;
	t_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*cheapest;

	init_stackb(a, b);
	mini_sort(a);
	while (*b)
	{
		nodes_init(*a, *b);
		push_nodes(a, b);
	}
	get_pos(*a);
	cheapest = get_smallest_node(*a);
	if (!(cheapest->above_middle))
		while (cheapest != *a)
			rra(a, 1);
	else if (cheapest->above_middle)
		while (cheapest != *a)
			ra(a, 1);
}
