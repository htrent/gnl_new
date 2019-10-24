#include "get_next_line.h"
#include <stdio.h>

t_list	*ft_find_fd(t_list *head, const int fd)
{
	t_list *ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->content_size == (size_t)fd)
			return(ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_list	*ft_create_node(char *content, size_t fd)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = (void *)content;
	list->content_size = fd;
	list->next = NULL;
	return (list);
}


int		ft_check_and_pull(t_list *node, char **line)
{
	char *newline;
	char *to_del;

	if (!node)
	{
		*line = ft_strnew(0);
		return (0);
	}
	//printf("cont : \'%s\'", node->content);
	newline = ft_strchr(node->content, '\n');
	if (newline)
	{
		*(newline++) = '\0';
		*line = ft_strdup(node->content);
		to_del = node->content;
		node->content = ft_strdup(newline);
		free(to_del);
		return (1);
	}
	*line = ft_strdup(node->content);
	node->content = ft_strnew(0);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	int 			rt;
	char 			buf[BUFF_SIZE + 1];
	char 			*newline;
	t_list			*node;
	char 			*to_del;

	if (read(fd, buf, 0) == -1 || line == NULL)
		return (-1);
	if (*line)
		free(*line);
	newline = NULL;
	node = ft_find_fd(list, fd);
	if (ft_check_and_pull(node, line))
		return (1);
	//printf("Beginning...\n");
	//getchar();
	//printf("Perv line: \'%s\'\n", *line);
	//if (node)
	//	printf("Perv list: \'%s\'\n", node->content);
	//getchar();
	while (!newline && (rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
	//	printf("buf = \'%s\'\n", buf);
		//getchar();
		if (node == NULL)
		{
		//	printf("Node doesn\'t exist...\n");
			node = ft_create_node(ft_strdup(buf), fd);
			ft_lstadd(&list, node);
		}
		else
			node->content = ft_strjoin(node->content, buf);
		//printf("Content of node: \'%s\'\n", node->content);
		//getchar();
		newline = ft_strchr(node->content, '\n');
	}
	if (newline)
		*(newline++) = '\0';
	*line = ft_strjoin(*line, node->content);
	to_del = node->content;
	node->content = ft_strdup(newline);
	free(to_del);
	*line = ft_strjoin(*line, node->content);
	if (rt == 0)
		free(node->content);
	if (rt == 0 && ft_strlen(*line) == 0 && ft_strlen(node->content) == 0)
		return (0);
	return (1);
}
