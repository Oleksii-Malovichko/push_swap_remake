/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:51 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 13:55:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(unsigned char ch)
{
	int	num;
	int	i;

	i = 0;
	num = ch - '0';
	while (i <= 9)
	{
		if (i == num)
			return (1);
		i++;
	}
	return (0);
}

void	handle_error(void)
{
	ft_printf("Error\n");
	exit (1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	valid_num(const char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(int num, t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}
