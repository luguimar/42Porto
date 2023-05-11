/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:26:57 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/11 16:38:34 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

#include <stdio.h>

void	*ft_lsttoupper(void *content)
{
	int	i;
	char	*str;
	char	*new_str;

	str = (char *) content;
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i] != '\0')
	{
		new_str[i] = ft_toupper(str[i]);
		i++;
	}
	return (new_str);
}

void	delcontent(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	**headerlista;
	t_list	**headerlistanova;
	t_list	*lista;
	t_list	*lista1;
	t_list	*lista2;
	t_list	*lista3;
	t_list	*templist;

	headerlista = (t_list **)malloc(sizeof(t_list *));
	headerlistanova = (t_list **)malloc(sizeof(t_list *));
	lista = ft_lstnew("abcdefg");
	lista1 = ft_lstnew("hijkl");
	lista2 = ft_lstnew("mnopq");
	lista3 = ft_lstnew("rstuvwxyz");
	*headerlista = lista;
	ft_lstadd_back(headerlista, lista1);
	ft_lstadd_back(headerlista, lista2);
	ft_lstadd_back(headerlista, lista3);
	*headerlistanova = ft_lstmap(lista, ft_lsttoupper, delcontent);
	templist = *headerlistanova;
	while (templist->next)
	{
		printf("%s\n", (char *)templist->content);
		templist = templist->next;
	}
	ft_lstclear(headerlistanova, delcontent);
	ft_lstclear(headerlista, delcontent);
	return (0);
}
