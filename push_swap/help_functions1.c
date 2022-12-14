/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:53:55 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:18:48 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b) 
{
	int swap;
	
	swap = *a;
	*a = *b;
	*b = swap;
}

int list_size(t_stack *stack)
{
	int size;
	t_stack *tmp;

	tmp = stack;
	size = 0;
	if (!stack)
		return 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_stack *last_node(t_stack *list) 
{
  t_stack *tmp;
  tmp = list;

  while (tmp->next && tmp)
    tmp = tmp->next;
  return (tmp);
}

int argv_len(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
        i++;
    return (i);
}


