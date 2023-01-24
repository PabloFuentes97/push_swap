/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/20 11:51:39 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list{
	int				nb;
	int				sort_pos;
	int				bin;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list		*ft_lstnew(int nb);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		swap_head(t_list **head, t_list *new_head);
int			ft_atoi(const char *str);
void		swap(t_list **head, char c);
void		ss(t_list **head_a, t_list **head_b);
void		push(t_list **head1, t_list **head2, char c);
void		rotate(t_list **head, t_list **tail, char c);
void		rr(t_list **head_a, t_list **head_b,
				t_list **tail_a, t_list **tail_b);
void		reverse_rotate(t_list **head, t_list **tail, char c);
void		rrr(t_list **head_a, t_list **head_b,
				t_list **tail_a, t_list **tail_b);
t_list		*array_to_list(int *array_num, int len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
void		free_matrix(char **matrix);
int			check_number(char *argv);
int			count_numbers(char *array);
int			check_repeat(int *array, int len);
int			check_max_int(char *array);
int			*check_one_arg(char **args, int len);
int			*check_multiple_args(char **args, int len);
int			*ft_intcpy(int *dest, int *src, int len);
char		**ft_split(char const *s, char c);
t_list		*arg_to_list(char **argv);
int			*sort_pos(int *sort_array, int *org_array, int len);
int			*sort_array(int *array, int len);
t_list		*sort_two(t_list *head);
t_list		*sort_three(t_list *head, t_list *tail);
t_list		*sort_four(t_list *head, t_list *tail);
t_list		*sort_five(t_list *head, t_list *tail);
int			sort_checker(t_list *head);
t_list		*find_node(t_list *head, int pos);
int			to_binary(int n);
void		binary_member(t_list **head, int *pos_array, int len);
int			num_len(unsigned int n);
int			max_binary(t_list *head);
int			max_number(t_list *head);
int			max_digits(t_list *head);
t_list		*call_radix_sort(t_list *head);
t_list		*radix_sort(t_list *head, t_list *tail,
				t_list *stack_b, int digits);
int			min_number(t_list *head);
int			last_is_min(t_list *tail);
void		*push_swap(t_list *head);

#endif
