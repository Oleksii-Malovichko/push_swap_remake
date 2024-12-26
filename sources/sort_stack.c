/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:25:18 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 13:25:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	else if (count == 2)
		swap(*stack_a, 'a');
	else if (count == 3)
		simple_sort(stack_a);
	else if (count > 3)
		long_sort(stack_a, stack_b);
	else
		handle_error();
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack || !stack->next)
		return (1);
	temp = stack;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	simple_sort(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(*stack))
		return ;
	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c && a < c)
		swap(*stack, 'a');
	else if (a > b && b > c && a > c)
	{
		swap(*stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(stack, 'a');
	else if (a < b && b > c && a < c)
	{
		swap(*stack, 'a');
		rotate(stack, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, 'a');
}

void	long_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*stack_a);
	if (size_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 'b');
	if (size_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 'b');
	while (size_a > 3 && !is_sorted(*stack_a))
	{
		init_stack(*stack_a, *stack_b, 'a', 'b');
		push_to_target_stack(stack_a, stack_b);
		size_a--;
	}
	simple_sort(stack_a);
	size_b = stack_size(*stack_b);
	while (size_b > 0)
	{
		init_stack(*stack_b, *stack_a, 'b', 'a');
		push_to_target_stack(stack_b, stack_a);
		size_b--;
	}
	init_stack_basics(*stack_a, 'a');
	check_min_on_top(stack_a);
}
