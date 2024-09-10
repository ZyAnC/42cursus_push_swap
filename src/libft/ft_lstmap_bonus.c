/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:18:38 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/19 15:18:39 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ftadd(t_list *l, t_list **r, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newnode;
	void	*content;

	while (l)
	{
		content = f(l->content);
		if (!content)
		{
			ft_lstclear(r, d);
			return (0);
		}
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			d(content);
			ft_lstclear(r, d);
			return (0);
		}
		ft_lstadd_back(r, newnode);
		l = l->next;
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	if (!ftadd(lst, &result, f, del))
		return (NULL);
	return (result);
}
/*

#include <stdio.h>
void *double_content(void *content) {
    int *result = malloc(sizeof(int));
    *result = 2 * (*(int *)content);
    return result;
}


void free_content(void *content) {
    free(content);
}// Print the content of the list for testing results
void print_list(t_list *lst) {
    while (lst != NULL) {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    t_list *list = NULL, *mapped_list = NULL;
    int values[] = {1, 2, 3, 4, 5};

    // Create the list
    for (int i = 0; i < 5; i++) {
        int *new_val = malloc(sizeof(int));
        *new_val = values[i];
        ft_lstadd_back(&list, ft_lstnew(new_val));
    }

    // Apply ft_lstmap and print results
    mapped_list = ft_lstmap(list, double_content, free_content);
    print_list(mapped_list);

    // Clean up
    while (list) {
        t_list *temp = list->next;
        ft_lstdelone(list, free_content);
        list = temp;
    }
    while (mapped_list) {
        t_list *temp = mapped_list->next;
        ft_lstdelone(mapped_list, free_content);
        mapped_list = temp;
    }
}
*/
