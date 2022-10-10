#include "push_swap.h"

int checks_order(t_stack *list)
{
	t_stack *tmp;

	tmp = list;
	if (!tmp)
		return (1);
	
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int checks_order_argv(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int find_max_number(t_stack **list) {
  int max;
  t_stack *tmp;

  tmp = *list;
  max = tmp->index;

  while (tmp) {
    if (tmp->index > max)
      max = tmp->index;
    tmp = tmp->next;
  }
  return (max);
}

int max_bits_size(t_stack **list)
{
	int	n;
	int res; //  1 mais a esquerda

	n = find_max_number(list);
	res = 1;
	while(n > 1)
	{
		res++;
		n /= 2;
	}
	return (res);
}

int *find_min_number(t_stack **list) {
  int *min;
  int swap;
  t_stack *tmp;

  min = malloc(2 * sizeof(int));
  tmp = *list;
  min[0] = tmp->num;
	while(tmp)
	{
		if(tmp->num < min[0])
			min[0] = tmp->num;
		tmp = tmp->next;		
	}
	tmp = *list;
	if (tmp->num != min[0])
		min[1] = tmp->num;
	else
		min[1] = tmp->next->num;
	while(tmp)
	{
		if (tmp->num != min[0] && tmp->num < min[1])
			min[1] = tmp->num;
		tmp = tmp->next;
	}
    return (min);
}
