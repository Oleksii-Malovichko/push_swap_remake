/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:22:25 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 17:28:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	dial_with_rrr(char **temp, int **stack_a, int **stack_b, t_lens **lens)
{
	if (ft_memcmp(*temp, "rra\n", 4) == 0)
		reverse_rotate_a(*stack_a, *(*lens)->stack_a_len);
	else if (ft_memcmp(*temp, "rrb\n", 4) == 0)
		reverse_rotate_b(*stack_b, *(*lens)->stack_b_len);
	else
	{
		reverse_rotate_rr(*stack_a, *(*lens)->stack_a_len,
			*stack_b, *(*lens)->stack_b_len);
	}
}

void	dial_with_ss(char **temp, int **stack_a,
			int **stack_b, t_lens **lens)
{
	if (ft_memcmp(*temp, "sa\n", 3) == 0)
		swap_a(stack_a, *(*lens)->stack_a_len);
	else if (ft_memcmp(*temp, "sb\n", 3) == 0)
		swap_b(stack_b, *(*lens)->stack_b_len);
	if (ft_memcmp(*temp, "ss\n", 3) == 0)
		swap_ss(stack_a, *(*lens)->stack_a_len, stack_b, *(*lens)->stack_b_len);
}

void	dial_with_p(char **temp, int **stack_a,
			int **stack_b, t_lens **lens)
{
	if (ft_memcmp(*temp, "pa\n", 3) == 0)
		push_a(stack_a, (*lens)->stack_a_len, stack_b, (*lens)->stack_b_len);
	else if (ft_memcmp(*temp, "pb\n", 3) == 0)
		push_b(stack_b, (*lens)->stack_b_len, stack_a, (*lens)->stack_a_len);
}

void	dial_with_rr(char **temp, int **stack_a,
			int **stack_b, t_lens **lens)
{
	if (ft_memcmp(*temp, "ra\n", 3) == 0)
		rotate_a(*stack_a, *(*lens)->stack_a_len);
	else if (ft_memcmp(*temp, "rb\n", 3) == 0)
		rotate_b(*stack_b, *(*lens)->stack_b_len);
	else
	{
		rotate_rr(*stack_a, *(*lens)->stack_a_len,
			*stack_b, *(*lens)->stack_b_len);
	}
}

int	choose_operation(int **stack_a, int **stack_b, t_lens **lens, char **temp)
{
	if (ft_memcmp(*temp, "rra\n", 4) == 0
		|| ft_memcmp(*temp, "rrb\n", 4) == 0
		|| ft_memcmp(*temp, "rrr\n", 4) == 0)
	{
		dial_with_rrr(temp, stack_a, stack_b, lens);
	}
	else if (ft_memcmp(*temp, "sa\n", 3) == 0
		|| ft_memcmp(*temp, "sb\n", 3) == 0
		|| ft_memcmp(*temp, "ss\n", 3) == 0)
	{
		dial_with_ss(temp, stack_a, stack_b, lens);
	}
	else if (ft_memcmp(*temp, "pa\n", 3) == 0
		|| ft_memcmp(*temp, "pb\n", 3) == 0)
	{
		dial_with_p(temp, stack_a, stack_b, lens);
	}
	else if (ft_memcmp(*temp, "ra\n", 3) == 0
		|| ft_memcmp(*temp, "rb\n", 3) == 0 || ft_memcmp(*temp, "rr\n", 3) == 0)
	{
		dial_with_rr(temp, stack_a, stack_b, lens);
	}
	else
		return (free(*lens), 0);
	return (1);
}
