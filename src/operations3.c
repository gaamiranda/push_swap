/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:35:07 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:35:08 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rot(t_node **stack)
{
	t_node	*tmp;
	t_node	*prev;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack;
	*stack = tmp;
	prev->next = NULL;
}

void	rra(t_node **a, int control)
{
	reverse_rot(a);
	if (control)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int control)
{
	reverse_rot(b);
	if (control)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, int control)
{
	reverse_rot(a);
	reverse_rot(b);
	if (control)
		write(1, "rrr\n", 4);
}
