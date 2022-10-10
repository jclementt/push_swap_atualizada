/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_libft2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclement <jclement@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:30:03 by jclement          #+#    #+#             */
/*   Updated: 2022/10/10 19:31:35 by jclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlen(const char *s)
{
  size_t i;

  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}

int ft_isdigit(int c) 
{
  if (c >= '0' && c <= '9')
    return (0);
  return (1);
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

int ft_strcmp(const char *s1, const char *s2)
{
    unsigned char   *ps1;
    unsigned char   *ps2;
    size_t          i;

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

