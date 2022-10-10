/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:52:35 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:27:40 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int argv_len(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
        i++;
    return (i);
}

char	**treat_argv(int argc, char **argv)
{
	char	*new_argv;
	char	*tmp;
	char	**res;
	int		i;

	i = 1;
	new_argv = ft_strjoin("./push_swap ", "");
	printf("new argv inicial: %s\n", new_argv);
	while (i < argc)
	{
		tmp = new_argv;
		new_argv = ft_strjoin(new_argv, argv[i]);
		free(tmp);
		tmp = new_argv;
		new_argv = ft_strjoin(new_argv, " ");
		free(tmp);
		i++;
	}
	printf("new argv final: %s\n", new_argv);
	res = ft_split(new_argv, ' ');
	free(new_argv);
	return (res);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**new_argv;
	int		size;

	new_argv = treat_argv(argc, argv);
	argc = argv_len(new_argv);
	stack = copy_args_stack(argc, new_argv);
	free_matrix(new_argv);
	if ((!validate_argv(argc, argv) || !(stack)) && argc != 1)
	{
		stack_free(&stack);
		write(2, "Error\n", 6);
		return (0);
	}
	size = list_size(stack);
	if (checks_order(stack))
	{
		stack_free(&stack);
		return (0);
	}
	sort_methods(&stack, size);
	return (0);
}

