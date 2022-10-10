#include "push_swap.h"

void	apply_operations(t_stack **a, t_stack **b, char *op)
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

void sort_short(t_stack **stack, int len) {
  if (len == 1 || (len == 2 && (*stack)->num < (*stack)->next->num))
    return;
  if (len == 2) {
    printf("sa\n");
    sab(*stack);
  }
  if (len == 3)
    sort_three(stack, len);
}

void sort_three(t_stack **list, int len) 
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
