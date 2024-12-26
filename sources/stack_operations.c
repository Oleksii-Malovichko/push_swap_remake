/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:24:14 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 13:24:15 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **src, t_stack **dest, char stack_name)
{
	t_stack	*temp;

	if (*src == NULL)
	{
		return ;
	}
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	if (ft_isalpha(stack_name))
		ft_printf("p%c\n", stack_name);
}

void	reverse_rotate(t_stack **stack, char stack_name)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_size(*stack) >= 2)
	{
		temp = *stack;
		last = last_node(*stack);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	if (ft_isalpha(stack_name))
		ft_printf("rr%c\n", stack_name);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, int print)
{
	reverse_rotate(a, '0');
	reverse_rotate(b, '0');
	if (print == 1)
	{
		ft_printf("rrr\n");
	}
}

void	rotate(t_stack **stack, char stack_name)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_size(*stack) >= 2)
	{
		temp = *stack;
		*stack = temp->next;
		temp->next = NULL;
		last = last_node(*stack);
		last->next = temp;
	}
	if (ft_isalpha(stack_name))
		ft_printf("r%c\n", stack_name);
}

void	rotate_both(t_stack **a, t_stack **b, int print)
{
	rotate(a, '0');
	rotate(b, '0');
	if (print == 1)
		ft_printf("rr\n");
}
