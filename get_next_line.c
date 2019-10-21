

#include "get_next_line.h"

char	*ft_check_list(t_list **head, const int fd)
{
	t_list 	*ptr;
	char 	*str;
	char 	*newline;
	t_list 	*prev;
	t_list *to_del;

	prev = NULL;
	str = ft_strnew(0);
	if (head == NULL)
		return (NULL);
	ptr = *head;
	while (ptr)
	{
		if (ptr->content_size == fd && (newline = ft_strchr(ptr->content, '\n')))
		{
			*newline = '\0';
			str = ft_strdup(ptr->content);
			ptr->content = newline++; ///def______________dangerous
			if (!prev)
			{
					to_del = ptr;
					
			}
			return (str);
		}
		else if (ptr->content_size == fd)
			str = ft_strjoin(str, ptr->content);
		prev = ptr;
		ptr = ptr->next;
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	const t_list	*list;
	int 			rt;
	char 			buf[BUF_SIZE + 1];
	char 			*newline;
	t_list			*node;

	new_line = NULL;
	node = NULL;
	if (read(fd, buf, 0) == -1 || line == NULL || *line == NULL)
		return (-1);
	if ((*list = ft_check_list(&list, fd)))
		return (1);
	while (!newline && (rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		if (!node)
			node = ft_lstadd_back(&list, ft_lstnew(buf, fd));
		else
			node->content = ft_strjoin(buf, node->content);
		newline = ft_strchr(list->content, '\n');
	}

}
