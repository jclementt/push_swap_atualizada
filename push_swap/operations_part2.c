#include "push_swap.h"

// o primeiro elemento de A se torna o ultimo
int rab(t_stack **ab) 
{
	t_stack *tmp;
	t_stack *first_node;
	t_stack *last_node;

	tmp = *ab;
	
	if (!(tmp && tmp->next))
		return (0);

	first_node = tmp;
	tmp = tmp->next;
	last_node = tmp;
	
	while (last_node->next && last_node)
		last_node = last_node->next;
  
	last_node->next = first_node;
	first_node->next = NULL;
	*ab = tmp;
	return (0);
}

int rr(t_stack **a, t_stack **b) 
{
	rab(a);
	rab(b);
	return(0);
}

// o ultimo elemento de A passa a ser o primeiro
int rrab(t_stack **ab) 
{
	t_stack *tmp;
	t_stack *penult_node;
	t_stack *last_node;

	tmp = *ab;
	
	if (!(tmp && tmp->next))
		return (0);

	penult_node = tmp;
	//tmp = tmp->next;
	last_node = tmp;
	
	while (penult_node->next->next && penult_node)
		penult_node = penult_node->next;

	last_node = penult_node->next;
	last_node->next = tmp;
	penult_node->next = NULL;
 
	*ab = last_node;
	return (0);
}

int rrr(t_stack **a, t_stack **b) 
{
	rrab(a);
	rrab(b);
	return (0);
}
