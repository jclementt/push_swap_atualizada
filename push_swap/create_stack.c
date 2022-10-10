/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:54:35 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 18:54:37 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(void)
{
	t_stack	*first_node;

	first_node = (t_stack*)malloc(sizeof(t_stack));
	first_node->num = 0;
	first_node->index = 0;
	first_node->next = NULL;
	return (first_node);
}

t_stack *copy_args_stack(int argc, char **argv) 
{
	t_stack *list;
	t_stack	*tmp;
	int i;
	
	i = 1;
	list = create_node();
	tmp = list;
	while(i < argc)
	{
		if (check_argv(argv[i]))
		{
			stack_free(&list);
			return (NULL);
		}
		tmp->num = ft_atoi(argv[i]);
		tmp->index = find_index(argv, argc, tmp->num);
		if (i < argc - 1)
		{
			tmp->next = create_node();
			tmp = tmp->next;
		}
	    i++;
	}
	return (list);
}

int find_index(char **argv, int argc, int num) 
{
  int i;
  int index;

  i = 1;
  index = 0;
  while (i < argc)
  {
    if (atoi(argv[i]) < num)
      index++;
    i++;
  }
  return (index);
}
