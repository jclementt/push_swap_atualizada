/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cheking1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:54:24 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:45:46 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int check_duplicate(int argc, char **argv)
{
    int i;
    int j;
    int counter;

    i = 1;

    counter = 0;
    while (i < argc)
    {
        j = 1;
        counter = 0;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                counter++;
            if (counter > 1)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int validate_argv(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    if (checks_order_argv(argc, argv))
        return (0);
    if (!check_duplicate(argc, argv))
        return (0);
    return (1);
}



