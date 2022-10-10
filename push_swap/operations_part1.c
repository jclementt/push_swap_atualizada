/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:53:35 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:22:29 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sab(t_stack *ab) 
{
	t_stack *tmp;
	
	tmp = ab;
	if (tmp->next && tmp)
		ft_swap(&tmp->num, &tmp->next->num);
	return (0);
}

int ss(t_stack *a, t_stack *b) 
{
	sab(a);
	sab(b);
	return (0);
}

int pab(t_stack **a, t_stack **b) 
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	t_stack *first_node;
	
	tmp_a = *a;
	tmp_b = *b;

	if (!b)
		return (0);
	first_node = tmp_b;
	tmp_b = tmp_b->next;
	*b = tmp_b;
	if (!tmp_a)
	{
		tmp_a = first_node; 
		tmp_a->next = NULL; 
		*a = tmp_a; 
	}
	else
	{
		first_node->next = tmp_a;
		*a = first_node;
	}
	return (0);
}

    void    apply_operations(t_stack **a, t_stack **b, char *op)
{
    if (!ft_strcmp(op, "pa"))
    {
        pab(a, b);
        write(1, "pa\n", 3);
    }
    else if (!ft_strcmp(op, "pb"))
    {
        pab(b, a);
        write(1, "pb\n", 3);
    }
    else if (!ft_strcmp(op, "ra"))
    {
        rab(a);
        write(1, "ra\n", 3);
    }
    else if (!ft_strcmp(op, "rra"))
    {
        rrab(a);
        write(1, "rra\n", 4);
    }
    else if (!ft_strcmp(op, "rrb"))
    {
        rrab(b);
        write(1, "rrb\n", 4);
    }
}

