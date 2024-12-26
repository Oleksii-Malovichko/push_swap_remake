/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:30:50 by alex              #+#    #+#             */
/*   Updated: 2024/12/26 18:13:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_lens
{
	int	*stack_a_len;
	int	*stack_b_len;
}	t_lens;

int		make_actions(char **temp, int **stack_a,
			int *stack_a_len, int flag_finish);
int		get_data(int **stack_a, int *stack_a_len);
int		is_sorted(int *stack_a, int stack_a_len);
int		ft_error(void);
int		check_chars(char *nums);
char	*ft_strncpy(char *args, int i_start, int i_end);
int		get_nums(int **stack_a, char **args);
int		get_len_stack(char *args);
int		ft_strlen2(char *str);
int		ft_atoi(char *str, int *flag);
void	just_free(int **stack_a, char **temp);
char	*ft_strdup(const char *s1);
void	free_stacks(int **stack_a, char **temp);
int		ft_error_exit(void);
void	print_a(int *stack_a, int stack_a_len);
void	print_b(int *stack_a, int stack_a_len);
void	rotate_rr(int *stack_a, int stack_a_len, int *stack_b, int stack_b_len);
void	reverse_rotate_a(int *stack_a, int stack_a_len);
void	reverse_rotate_b(int *stack_b, int stack_b_len);
void	reverse_rotate_rr(int *stack_a, int stack_a_len,
			int *stack_b, int stack_b_len);
void	swap_a(int **stack_a, int stack_a_len);
void	swap_b(int **stack_b, int stack_b_len);
void	swap_ss(int **stack_a, int stack_a_len, int **stack_b, int stack_b_len);
int		*pop_item(int **stack_a, int stack_a_len);
int		*push_item(int **stack_a, int stack_a_len, int new);
void	push_a(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len);
void	push_b(int **stack_b, int *stack_b_len,
			int **stack_a, int *stack_a_len);
void	rotate_a(int *stack_a, int stack_a_len);
void	rotate_b(int *stack_b, int stack_b_len);
char	**ft_split(char const *s, char c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	dial_with_rrr(char **temp, int **stack_a, int **stack_b, t_lens **lens);
void	dial_with_ss(char **temp, int **stack_a,
			int **stack_b, t_lens **lens);
void	dial_with_p(char **temp, int **stack_a,
			int **stack_b, t_lens **lens);
void	dial_with_rr(char **temp, int **stack_a,
			int **stack_b, t_lens **lens);
int		choose_operation(int **stack_a, int **stack_b,
			t_lens **lens, char **temp);

#endif