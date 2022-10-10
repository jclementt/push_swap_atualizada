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

