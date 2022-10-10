#include "push_swap.h"

int check_int(char *str)
{
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int check_argv(char *str)
{
	int i;
	int size;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		return (1);
	if (str[i] == '-' && !ft_isdigit(str[i + 1]))
		i++;
	size = ft_strlen(&str[i]);
	if (size > 10)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (size == 10 && check_int(str))
		return (1);
	return (0);
}

void stack_free(t_stack **stack)
{
	t_stack *tmp;
	t_stack *del;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

void free_matrix(char **list)
{
	int i;

	i = 0;
	while(list[i])
	{
		free(list[i]);		
		i++;
	}
	free(list);
}