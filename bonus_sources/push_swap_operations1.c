/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:36:08 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 18:09:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_data(int **stack_a, int *stack_a_len)
{
	char	*temp;

	temp = get_next_line(0);
	while (temp != NULL)
	{
		if (!make_actions(&temp, stack_a, stack_a_len, 0))
			return (free(temp), 0);
		temp = get_next_line(0);
	}
	return (1);
}

void	rotate_rr(int *stack_a, int stack_a_len, int *stack_b, int stack_b_len)
{
	rotate_a(stack_a, stack_a_len);
	rotate_b(stack_b, stack_b_len);
}

void	reverse_rotate_a(int *stack_a, int stack_a_len)
{
	int	last_elem;
	int	i;

	if (stack_a_len <= 1)
		return ;
	last_elem = stack_a[stack_a_len - 1];
	i = stack_a_len - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = last_elem;
}

void	reverse_rotate_b(int *stack_b, int stack_b_len)
{
	int	last_elem;
	int	i;

	if (stack_b_len <= 1)
		return ;
	last_elem = stack_b[stack_b_len - 1];
	i = stack_b_len - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = last_elem;
}

void	reverse_rotate_rr(int *stack_a, int stack_a_len,
			int *stack_b, int stack_b_len)
{
	reverse_rotate_a(stack_a, stack_a_len);
	reverse_rotate_b(stack_b, stack_b_len);
}

// void	print_a(int *stack_a, int stack_a_len)
// {
// 	printf("Stack_a:\n");
// 	for (int i = 0; i < stack_a_len; i++)
// 		printf("%d ", (stack_a)[i]);
// 	printf("\n");
// }
// void	print_b(int *stack_a, int stack_a_len)
// {
// 	printf("Stack_b:\n");
// 	for (int i = 0; i < stack_a_len; i++)
// 		printf("%d ", (stack_a)[i]);
// 	printf("\n");
// }