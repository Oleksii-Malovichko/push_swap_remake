/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:33:15 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 17:21:59 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(int *stack_a, int stack_a_len)
{
	int	i;

	i = 0;
	while (i < (stack_a_len - 1))
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*s2;
	int		i;

	len_s1 = 0;
	i = 0;
	while (s1[len_s1] != '\0')
	{
		len_s1++;
	}
	s2 = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (i < len_s1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	just_free(int **stack_a, char **temp)
{
	free(*stack_a);
	*stack_a = NULL;
	free(*temp);
	*temp = NULL;
}

void	free_stacks(int **stack_a, char **temp)
{
	if (*stack_a != NULL)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (*temp != NULL)
	{
		free(*temp);
		*temp = NULL;
	}
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
