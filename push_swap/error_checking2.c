/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cheking2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:26:58 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:45:42 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

