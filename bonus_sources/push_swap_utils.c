/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:56:16 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 14:35:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

void	helper_to_check_char(char *nums, int i, int *wait_space)
{
	if (nums[i] >= '0' && nums[i] <= '9')
		*wait_space = 1;
	if (nums[i] == ' ')
		*wait_space = 0;
}

int	helper_to_check_char2(char *nums, int i, int flag, int wait_space)
{
	if (nums[i] != ' ' && flag == 0)
		return (0);
	if (wait_space == 1)
		return (0);
	return (1);
}

int	check_chars(char *nums)
{
	int	i;
	int	flag;
	int	wait_space;

	i = 0;
	wait_space = 0;
	flag = 0;
	while (nums[i] != '\0')
	{
		helper_to_check_char(nums, i, &wait_space);
		if (nums[i] < '0' || nums[i] > '9')
		{
			if (nums[i] == '-' && nums[i + 1] >= '0' && nums[i + 1] <= '9')
			{
				flag = 1;
				i++;
			}
			if (!helper_to_check_char2(nums, i, flag, wait_space))
				return (0);
			flag = 0;
		}
		i++;
	}
	return (1);
}

char	*ft_strncpy(char *args, int i_start, int i_end)
{
	char	*temp;
	int		i;

	if (i_end <= i_start)
		return (NULL);
	temp = malloc(sizeof(char) * ((i_end - i_start) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i_start < i_end)
	{
		temp[i] = args[i_start];
		i++;
		i_start++;
	}
	temp[i] = '\0';
	return (temp);
}
