/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:24:14 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/26 17:17:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*push_item(int **stack_a, int stack_a_len, int new)
{
	int	i;
	int	*temp;

	temp = malloc(sizeof(int) * (stack_a_len + 1));
	if (!temp)
		ft_error_exit();
	i = 0;
	temp[0] = new;
	while (i < stack_a_len)
	{
		temp[i + 1] = (*stack_a)[i];
		i++;
	}
	free(*stack_a);
	*stack_a = NULL;
	return (temp);
}

void	push_a(int **stack_a, int *stack_a_len, int **stack_b, int *stack_b_len)
{
	int	elem;

	if (*stack_b_len == 0)
		return ;
	elem = (*stack_b)[0];
	*stack_a = push_item(stack_a, *stack_a_len, elem);
	*stack_b = pop_item(stack_b, *stack_b_len);
	(*stack_a_len)++;
	(*stack_b_len)--;
}

void	push_b(int **stack_b, int *stack_b_len, int **stack_a, int *stack_a_len)
{
	int	elem;

	if (*stack_a_len == 0)
		return ;
	elem = (*stack_a)[0];
	*stack_b = push_item(stack_b, *stack_b_len, elem);
	*stack_a = pop_item(stack_a, *stack_a_len);
	(*stack_b_len)++;
	(*stack_a_len)--;
}

void	rotate_a(int *stack_a, int stack_a_len)
{
	int	first_elem;
	int	i;

	if (stack_a_len <= 1)
		return ;
	first_elem = stack_a[0];
	i = 0;
	while (i < stack_a_len - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[stack_a_len - 1] = first_elem;
}

void	rotate_b(int *stack_b, int stack_b_len)
{
	int	first_elem;
	int	i;

	if (stack_b_len <= 1)
		return ;
	first_elem = stack_b[0];
	i = 0;
	while (i < stack_b_len - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[stack_b_len - 1] = first_elem;
}
