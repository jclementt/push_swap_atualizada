/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:11:32 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:23:54 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_short(t_stack **stack, int len)
{
  if (len == 1 || (len == 2 && (*stack)->num < (*stack)->next->num))
    return;
  if (len == 2) {
    printf("sa\n");
    sab(*stack);
  }
  if (len == 3)
    sort_three(stack);
}

void    sort_methods(t_stack **stack, int size)
{
    if (size <= 3)
        sort_short(stack, size);
    else if (size <= 5)
        sort_five(stack);
    else
        radix_sort(stack, max_bits_size(stack));
    print_stack(*stack);
    stack_free(stack);
}

void sort_five(t_stack **list)
{
  t_stack *a;
  t_stack *b;
  int *min;
  int len;

  min = find_min_number(list);
  a = *list;
  b = NULL;
  len = list_size(a) + 1;
  while (len--) {
    if (a->num == min[0] || a->num == min[1]) {
      printf("pb\n");
      pab(&b, &a);
    } else {
      printf("ra\n");
      rab(&a);
    }
  }
  sort_five_2(&a, &b);
  free(min);
  *list = a;
}

void sort_five_2(t_stack **a, t_stack **b)
{
    int len;

    sort_short(a, list_size(*a));
    len = list_size(*b) + 1;
    if ((*b)->num < (*b)->next->num)
    {
        sab(*b);
        printf("sb\n");
    }
    pab(a, b);
    pab(a, b);
    printf("pa\npa\n");
}
