/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:34:22 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/08 15:34:24 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrrotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*dummy;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	dummy = *stack;
	while (dummy->next)
		dummy = dummy->next;
	dummy->next = tmp;
	tmp ->next = NULL;
}

void	ra(t_node **a, int control)
{
	rrrotate(a);
	if (control)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int control)
{
	rrrotate(b);
	if (control)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int control)
{
	rrrotate(a);
	rrrotate(b);
	if (control)
		write(1, "rr\n", 3);
}

void	ss(t_node **a, t_node **b, int control)
{
	swap(a);
	swap(b);
	if (control)
		write(1, "ss\n", 3);
}
