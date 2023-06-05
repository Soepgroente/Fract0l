/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:00:20 by vvan-der          #+#    #+#             */
/*   Updated: 2022/11/16 18:18:26 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int	ft_compare(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	ft_amount(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (ft_compare(*s1, set))
	{
		i++;
		s1++;
	}
	if (!*s1)
		return (i);
	while (*s1)
		s1++;
	s1--;
	while (ft_compare(*s1, set))
	{
		i++;
		s1--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	int		i;
	int		j;

	i = ft_amount(s1, set);
	j = ft_strlen(s1) - i + 1;
	trim = ft_calloc(j, sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (ft_compare(*s1, set))
		s1++;
	while (i < (j - 1))
	{
		trim[i] = *s1;
		i++;
		s1++;
	}
	return (trim);
} */

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*tmp;
	char	*trim;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	tmp = ft_strdup(s1);
	if (!tmp)
		return (NULL);
	if (!*tmp)
		return (tmp);
	trim = tmp;
	tmp += ft_strlen(tmp) - 1;
	while (ft_strchr(set, *tmp))
		tmp--;
	*(++tmp) = '\0';
	tmp = trim;
	trim = ft_strdup(trim);
	free(tmp);
	return (trim);
}

/* int main()
{
	char    *s1 = "12345";
	char    *set = "15";
	char    *result = ft_strtrim(s1, set);
	printf("Cut down in the praabaablaa:\n%s\n", result);
}
 */