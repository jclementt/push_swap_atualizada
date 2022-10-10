#include "push_swap.h"

size_t ft_strlen(const char *s) {
  size_t i;

  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}

int ft_isdigit(int c) {
  if (c >= '0' && c <= '9')
    return (0);
  return (1);
}

int ft_atoi(const char *str) 
{
  int i;
  long long int nb;
  int n;

  i = 0;
  n = 1;
  nb = 0;
 
  if (str[i] == '-')
    n = -1;
  if (str[i] == '-' || str[i] == '+')
    i++;
  while (str[i] >= '0' && str[i] <= '9') {
    nb = nb * 10 + (str[i] - '0');
    if (nb < 0 && n == -1 && nb != -2147483648)
      return (0);
    if (nb < 0 && n == 1)
      return (-1);
    i++;
  }
  return (nb * n);
}
void print_stack(t_stack *stack) {
  t_stack *tmp = stack;
  while (tmp) {
    printf("%d ", tmp->num);
    tmp = tmp->next;
  }
  printf("\n");
}

void print_stack_index(t_stack *stack) {
  t_stack *tmp = stack;
  while (tmp) {
    printf("num: %d, index: %d | \n", tmp->num, tmp->index);
    tmp = tmp->next;
  }
  printf("\n");
}

static int	words_counter(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			counter++;
		i++;
	}
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		arr[j++] = s[i++];
	arr[j] = '\0';
	return (arr);
}

static char	*word_finder(const char *s, char c, size_t n)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i] && counter <= n)
	{
		if (i == 0)
			i = 0;
		else if (s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			end = i;
			counter++;
		}
		i++;
	}
	return (ft_substr(s, start, end - start + 1));
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	char			**tmp;
	unsigned int	words;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	words = words_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (i < words)
	{
		arr[i] = word_finder(s, c, i);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char *ft_strjoin(char const *s1, char const *s2) {
  char *arr;
  unsigned int i;
  unsigned int j;

  i = 0;
  j = 0;
  if (!s1)
    return (NULL);
  arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
  if (!arr)
    return (NULL);
  while (s1[i]) {
    arr[i] = s1[i];
    i++;
  }
  while (s2[j])
    arr[i++] = s2[j++];
  arr[i] = '\0';
  return (arr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while ((ps1[i] || ps2[i]))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

