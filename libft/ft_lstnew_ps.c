/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:24:27 by vvan-der          #+#    #+#             */
/*   Updated: 2023/03/24 16:24:37 by vvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_ps(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
	{
		free(content);
		return (NULL);
	}
	n->content = content;
	n->next = NULL;
	return (n);
}
