/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:48:40 by domelche          #+#    #+#             */
/*   Updated: 2017/11/18 19:48:42 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*ptr_a;

	if (!(ptr_a = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	if (!((void*)content))
	{
		ptr_a->content = NULL;
		ptr_a->content_size = 0;
	}
	else
	{
		if (!(ptr_a->content = malloc(content_size)))
		{
			free(ptr_a);
			return (NULL);
		}
		ft_memmove(ptr_a->content, content, content_size);
		ptr_a->content_size = content_size;
	}
	ptr_a->next = NULL;
	ptr_a->prev = NULL;
	return (ptr_a);
}
