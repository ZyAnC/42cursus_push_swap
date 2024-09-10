/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:18:24 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/19 15:18:25 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int main() {
    t_list *head = NULL;
    t_list *last;

    // Adding nodes to the list
    ft_lstadd_back(&head, ft_lstnew("First node"));
    ft_lstadd_back(&head, ft_lstnew("Second node"));
    ft_lstadd_back(&head, ft_lstnew("Third node"));

    // Retrieve the last node
    last = ft_lstlast(head);
    if (last != NULL) {
        printf("The last node contains: %s\n", (char *)last->content);
    } else {
        printf("The list is empty.\n");
    }

    // Free the list
    while (head != NULL) {
        t_list *tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}*/
