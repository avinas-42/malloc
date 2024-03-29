/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:35:43 by avinas            #+#    #+#             */
/*   Updated: 2019/09/12 16:23:45 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libmalloc.h"
#include "../include/page_manager.h"
#include "../include/allocator.h"

void	*ft_malloc(size_t size)
{
	void	*ret;
	t_page	*page;

	ret = NULL;
	size = ALIGN16(size);
	if ((page = searchfreepage(size)) != NULL)
	{
		return (alloc(page, size));
	}
	createpage(size);
	if ((page = searchfreepage(size)) != NULL)
	{
		return (alloc(page, size));
	}
	return (ret);
}

void	*malloc(size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_mutex);
	ptr = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
