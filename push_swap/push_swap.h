#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>

typedef struct s_stack 
{
  int num;
  int index;
  struct s_stack *next;
} t_stack;

t_stack 	*create_node(void);
void 		print_stack(t_stack *stack); //exclui
void 		ft_swap(int *a, int *b);
int 		sab(t_stack *ab);
int 		rab(t_stack **ab);
int 		pab(t_stack **a, t_stack **b);
int 		rrab(t_stack **ab);
int 		rrr(t_stack **a, t_stack **b);
size_t		ft_strlen(const char *s); // LIBFT
void 		sort_five(t_stack **list);
void 		radix_sort(t_stack **list, int bit_max);
void 		radix_sort_2(t_stack **a, t_stack **b, int move, int bit_max);
t_stack		*last_node(t_stack *list);
t_stack		*copy_args_stack(int argc, char **argv);
int			check_int(char *str);
int 		check_argv(char *str);
void		stack_free(t_stack **stack);
int			ft_atoi(const char *str);
int			list_size(t_stack *stack);
void		sort_three(t_stack **list);
int			find_max_number(t_stack **list);
int			*find_min_number(t_stack **list);
void		sort_short(t_stack **stack, int len);
int			checks_order(t_stack *list);
int			find_index(char **argv, int argc, int num);
int			max_bits_size(t_stack **list);
int			validate_argv(int argc, char **argv);
int			checks_order_argv(int argc, char **argv);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
void		free_matrix(char **list);
void		sort_five_2(t_stack **a, t_stack **b);
int			ft_strcmp(const char *s1, const char *s2);
void		apply_operations(t_stack **a, t_stack **b, char *op);
void 		sort_methods(t_stack **stack, int len);
int			argv_len(char **argv);

#endif
