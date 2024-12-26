/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:24:21 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 13:34:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isalpha(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	return (0);
}

void	swap(t_stack *stack, char stack_name)
{
	int	temp;

	if (stack_size(stack) <= 1)
	{
		return ;
	}
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	if (ft_isalpha(stack_name))
	{
		ft_printf("s%c\n", stack_name);
	}
}

void	swap_both(t_stack *a, t_stack *b, int print)
{
	swap(a, '0');
	swap(b, '0');
	if (print == 1)
	{
		ft_printf("ss\n");
	}
}

t_stack	*last_node(t_stack *stack)
{
	t_stack	*last_entry;

	if (stack == NULL)
		return (NULL);
	last_entry = stack;
	while (last_entry->next != NULL)
		last_entry = last_entry->next;
	return (last_entry);
}
