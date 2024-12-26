/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:58:45 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 18:09:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_duplicates(int *stack_a, int len)
{
	int	i_main;
	int	i_el;

	i_main = 0;
	while (i_main < len)
	{
		i_el = i_main + 1;
		while (i_el < len)
		{
			if (stack_a[i_main] == stack_a[i_el])
				return (0);
			i_el++;
		}
		i_main++;
	}
	return (1);
}

char	*get_items(int n, char **args, char *result)
{
	int	q_elem;
	int	q_ch;
	int	counter;

	q_elem = 1;
	counter = 0;
	while (q_elem < n)
	{
		q_ch = 0;
		while (args[q_elem][q_ch] != '\0')
		{
			result[counter] = args[q_elem][q_ch];
			counter++;
			q_ch++;
		}
		if (q_elem < n - 1)
		{
			result[counter] = ' ';
			counter++;
		}
		q_elem++;
	}
	result[counter] = '\0';
	return (result);
}

char	*ft_myjoin(int n, char **args)
{
	int		counter;
	int		q_elem;
	int		q_ch;
	char	*result;

	counter = 0;
	q_elem = 1;
	while (q_elem < n)
	{
		q_ch = 0;
		while (args[q_elem][q_ch] != '\0')
		{
			q_ch++;
			counter++;
		}
		if (q_elem < n - 1)
			counter++;
		q_elem++;
	}
	result = malloc(sizeof(char) * (counter + 1));
	if (!result)
		return (NULL);
	return (get_items(n, args, result));
}

int	make_actions(char **temp, int **stack_a, int *stack_a_len, int flag_finish)
{
	static int	*stack_b = NULL;
	static int	stack_b_len = 0;
	t_lens		*lens;

	if (flag_finish)
	{
		if (is_sorted(*stack_a, *stack_a_len))
			return (free(stack_b), stack_b_len = 0, 1);
		return (free(stack_b), stack_b_len = 0, 0);
	}
	lens = (t_lens *)malloc(sizeof(t_lens));
	if (!lens)
		return (0);
	lens->stack_a_len = stack_a_len;
	lens->stack_b_len = &stack_b_len;
	if (ft_strlen2(*temp) > 4 || ft_strlen2(*temp) < 3)
		return (free(lens), 0);
	if (!choose_operation(stack_a, &stack_b, &lens, temp))
		return (free(lens), 0);
	return (free(*temp), free(lens), 1);
}

int	main(int n, char **args)
{
	int		*stack_a;
	char	*temp;
	int		stack_a_len;

	if (n == 1)
		return (1);
	stack_a = NULL;
	if (n == 2)
		temp = ft_strdup(args[1]);
	if (n > 2)
		temp = ft_myjoin(n, args);
	if (!temp)
		return (free_stacks(&stack_a, &temp), ft_error());
	if (!check_chars(temp))
		return (just_free(&stack_a, &temp), ft_error());
	stack_a_len = get_nums(&stack_a, &temp);
	if (!check_duplicates(stack_a, stack_a_len))
		return (just_free(&stack_a, &temp), ft_error());
	if (!get_data(&stack_a, &stack_a_len))
		return (free(stack_a), ft_error());
	if (!make_actions(&temp, &stack_a, &stack_a_len, 1))
		return (just_free(&stack_a, &temp), write(1, "KO\n", 3), 0);
	return (free(stack_a), free(temp), write(1, "OK\n", 3), 0);
}
