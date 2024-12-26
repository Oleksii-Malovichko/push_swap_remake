/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:24:32 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 13:42:50 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if ((sign * num) >= -2147483648 && (sign * num) <= 2147483647)
		return (sign * num);
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		neg;

	i = 0;
	num = 0;
	neg = 0;
	if (!str[i])
		return (0);
	while (ft_strchr(" \t\n\r\v\f", str[i]) != NULL)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		num *= -1;
	return (num);
}

static void	add_to_stack(t_stack **stack_a, int num)
{
	t_stack	*new_node;
	t_stack	*last;

	if (is_duplicate(num, *stack_a))
		handle_error();
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		handle_error();
	new_node->data = num;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = 0;
	new_node->name = 'A';
	new_node->target = NULL;
	new_node->next = NULL;
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}

static void	parse_str(char *str, t_stack **stack_a, int *count)
{
	int		i;
	int		num;
	char	**split_args;

	i = 0;
	split_args = ft_split(str, ' ');
	if (!split_args)
		handle_error();
	*count = 0;
	while (split_args[*count])
		(*count)++;
	while (split_args[i])
	{
		if (!valid_num(split_args[i]))
			handle_error();
		num = ft_atoi(split_args[i]);
		add_to_stack(stack_a, num);
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	parse_data(int ac, char *av[], t_stack **stack_a, int *count)
{
	int	num;
	int	i;

	if (ac > 2)
	{
		*count = ac - 1;
		i = 1;
		while (i <= *count)
		{
			if (!valid_num(av[i]))
				handle_error();
			num = ft_atoi(av[i]);
			add_to_stack(stack_a, num);
			i++;
		}
	}
	else if (ac == 2)
		parse_str(av[1], stack_a, count);
	if (is_sorted(*stack_a))
	{
		free_stack(*stack_a);
		exit(0);
	}
}
