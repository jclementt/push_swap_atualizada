#include "push_swap.h"

int argv_len(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return(i);
}

char **treat_argv(int argc, char **argv)
{
	char *new_argv;
	char *tmp;
	char **res;
	int i;
	
	i = 1;
	new_argv = ft_strjoin("./push_swap ", "");
	printf("new argv inicial: %s\n", new_argv);
	while(i < argc)
	{
		tmp = new_argv;
		new_argv = ft_strjoin(new_argv, argv[i]);
		free(tmp);
		tmp = new_argv;
		new_argv = ft_strjoin(new_argv, " ");
		free(tmp);
		i++;
	}
	printf("new argv final: %s\n", new_argv);
	res = ft_split(new_argv, ' ');
	free(new_argv);
	return (res);
}

int main(int argc, char **argv) 
{
	t_stack *stack;
	char **new_argv;
	int size;

	new_argv = treat_argv(argc, argv);
	argc = argv_len(new_argv);
	stack = copy_args_stack(argc, new_argv);
	free_matrix(new_argv);
	if ((!validate_argv(argc, argv) || !(stack)) && argc != 1) 
	{
		stack_free(&stack);
		write(2, "Error\n", 6);
		return (0);
	} 
	size = list_size(stack);
	if(checks_order(stack))
	{
		stack_free(&stack);
		return 0;
	}
	sort_methods(&stack, size);
	return (0);
}

void sort_methods(t_stack **stack, int size)
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

int check_duplicate(int argc, char **argv)
{
	int i;
	int j;
	int counter;

	i = 1;
	counter = 0;

	while (i < argc)
	{
		j = 1;
		counter = 0;
		
		while(j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				counter++;
			if (counter > 1)
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}

int validate_argv(int argc, char **argv)
{
	if(argc < 2)
		return (0);
	if(checks_order_argv(argc, argv))
		return (0);
	if(!check_duplicate(argc, argv))
		return (0);

	return (1);
}