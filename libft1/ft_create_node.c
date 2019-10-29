/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:45:13 by htrent            #+#    #+#             */
/*   Updated: 2019/09/17 18:02:59 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_node(char *content, size_t content_size)
{
    t_list	*list;

    list = (t_list *)malloc(sizeof(t_list));
    if (!list)
        return (NULL);
    list->content = (void *)content;
    list->content_size = content_size;
    list->next = NULL;
    return (list);
}

