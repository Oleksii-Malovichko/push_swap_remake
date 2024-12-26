/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:25:11 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 13:25:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_to_top(t_stack *node1, t_stack *node2, \
					t_stack **stack1, t_stack **stack2)
{
	if (node1->above_median && node2->above_median)
	{
		while (node1 != *stack1 && node2 != *stack2)
			rotate_both(stack1, stack2, 1);
	}
	if (!node1->above_median && !node2->above_median)
	{
		while (node1 != *stack1 && node2 != *stack2)
			reverse_rotate_both(stack1, stack2, 1);
	}
	while (node1 != *stack1)
	{
		if (node1->above_median)
			rotate(stack1, node1->name);
		else
			reverse_rotate(stack1, node1->name);
	}
	while (node2 != *stack2)
	{
		if (node2->above_median)
			rotate(stack2, node2->name);
		else
			reverse_rotate(stack2, node2->name);
	}
}

void	push_to_target_stack(t_stack **current, t_stack **target)
{
	t_stack	*push_node;

	if ((*current)->name == 'a')
		push_node = get_cheapest_node(*current);
	else
		push_node = *current;
	if (push_node != *current || push_node->target != *target)
		move_to_top(push_node, push_node->target, current, target);
	push(current, target, push_node->target->name);
}

void	check_min_on_top(t_stack **a)
{
	t_stack	*min;

	min = get_min(*a);
	if (*a != min)
	{
		if (min->above_median)
		{
			while (*a != min)
				rotate(a, 'a');
		}
		else
		{
			while (*a != min)
				reverse_rotate(a, 'a');
		}
	}
}
