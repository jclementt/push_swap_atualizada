/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:54:46 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:24:42 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **list)
{
  if ((*list)->num > (*list)->next->num)
  {
    printf("sa\n");
    sab(*list);
  }
  if ((*list)->next->next->num < (*list)->num) 
  {
    printf("rra\n");
    rrab(list);
  } 
  else if ((*list)->next->next->num < (*list)->next->num) 
  {
    printf("rra\nsa\n");
    rrab(list);
    sab(*list);
  }
  return;
}

void radix_sort(t_stack **list, int bit_max) 
{
  int i;
  int move;
  int len;
  t_stack *a;
  t_stack *b;

  move = -1;
  a = *list;
  b = NULL;
  bit_max--; 
  while (++move <= bit_max) 
  {
    if (checks_order(a) && list_size(b) == 0) 
      return;
    i = -1;
    len = list_size(a);
    while (++i < len) 
	{
      if ((a->index & (1 << move)) == 0) 
		  apply_operations(&a, &b, "pb");
	  else 
	  	apply_operations(&a, &b, "ra");
    }
	radix_sort_2(&a, &b, move, bit_max);
  }
	*list = a;
}

void radix_sort_2(t_stack **a, t_stack **b, int move, int bit_max)
{
	int  i;

	i = list_size(*b);
    while (i) 
	{
      if ((*b)->index & (1 << (move + 1)) || move == bit_max) 
	  {
        pab(a, b);
        printf("pa\n");
      } 
	  else 
	  {
        rab(b);
        printf("rb\n");
      }
      i--;
    }
}

