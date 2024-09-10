/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:05:08 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/10 18:07:08 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int stack_a[500];
int stack_b[500];
int top_a = -1;
int top_b = -1; 

int error()
{
    ft_putstr_fd("Error\n", 2);
    return (0);
}

int is_digit_str (char *str)
{
    if ((*str == '-' || *str == '+') && *(str + 1))
        str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

int is_overflow(char *str)
{
    int num;

    if (ft_strlen(str) > 10)
    {
        num = ft_atoi(str);
        if (num ==  -1 || num == 0)
            return (1);
    }
    return (0);
}
int is_valid(char *str)
{
    if (*str == '\0')
        return (0);
    if (!is_digit_str(str))
        return (0);
    if (is_overflow(str))
        return(0);
    return (1);
}

int    checkarg(int ac, char **av)
{
    int  i;
    i = 1;
    while(i < ac)
    {
        if (!is_valid(av[i]))
            return (0);
        i++;
    }
    return (1);

}

int *array_alloc(int size)
{
    int *res;
    
    res = malloc(sizeof(int) * size);
    if (!res)
        return (NULL);
    ft_memset (res, -1, sizeof(int));
    return (res);
}

int is_dup(int *a, int j)
{
    int cur;
    
    cur = a[j];
    j--;
    while (j >= 0)
    {
        if (a[j] == cur)
            return (1);
        j--;
    }
    return (0);
}

int array_fill(int *a, int n,  char **av)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
    while (i < n)
    {
        a[j] = ft_atoi(av[i]);
        if (is_dup(a, j))
            return (0);
        i++;
        j++;
    }
    return (1);
}

int fill_array(int ac, char **av, int **a, int **b)
{
    if (!*a || !*b || !array_fill(*a, ac ,av) || !array_fill(*b, ac ,av))
    {
        free(*a);
        free(*b);
        return (0);
    }
    return (1);
}

void    set_index(int *a, int *b, int n)
{
    int left;
    int right;
    int i;
    int cur;
    
    i = 0;
    while(i < n)
    {
        left = 0;
        right = n - 1;
        while(left <= right)
        {
            cur = left + (right - left) / 2;
            if(a[i] == b[cur])
                a[i] = cur;
            else if (b[cur] < a[i])
                left = cur + 1;
            else
                right = cur - 1;
        }
        i++;
    }
}
void	sort_and_index(int *a, int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
    set_index(a, tab, size);
    free(tab);
}

void is_sort(int *b, int n,int *a)
{
    int i;

    i = 1;
    while(i < n)
    {
        if(b[i] > b[i - 1])
            i++;
        else
            break;
    }
    if (i == n)
    {
        free(a);
        free(b);
        exit(0);
    }
}

void pb() 
{
    int i;
    
    if (top_a >= 0) 
    {
        stack_b[++top_b] = stack_a[0];
        i = 0;
        while (i < top_a) {
            stack_a[i] = stack_a[i + 1];
            i++;
        }
        top_a--;
        ft_printf("pb\n");
    }
}

void pa() {
    int i;

    if (top_b >= 0)
    {
        i = top_a + 1;
        while (i > 0) 
        {
            stack_a[i] = stack_a[i - 1];
            i--;
        }
        stack_a[0] = stack_b[top_b--];
        top_a++;
        ft_printf("pa\n");
    }
}

void ra() {
    int i;
    int temp;
    
    if (top_a > 0) 
    {
        temp = stack_a[0];
        i = 0;
        while (i < top_a) 
        {
            stack_a[i] = stack_a[i + 1];
            i++;
        }
        stack_a[top_a] = temp;
        ft_printf("ra\n");
    }
}



void radix_sort(int *a, int n)
{
    int max_index;
    int bits;
    int i;
    int j;
    
    bits = 0;
    max_index = n - 1;
    while (max_index >> bits)
        bits++;
    i = 0;
    while (i < n)
        stack_a[++top_a] = a[i++];
    i = 0;
    while (i < bits) 
    {
        j = 0;
        while (j < n) 
        {
            if (((stack_a[0] >> i) & 1) == 1)
                ra();
            else
                pb();
            j++;
        }
        while (top_b >= 0)
            pa(); 
        i++;
    }
}
    

void    push_swap(int **a, int **b, int n)
{
    is_sort(*b, n, *a);
    sort_and_index(*a, *b, n);   
    radix_sort(*a, n);
     free(*a);

    
}
int main(int ac, char **av)
{   
    int *a;
    int *b;

    if (ac < 2)
        return (0);
    if (!checkarg(ac, av))
        return (error());
    a = array_alloc(ac - 1);
    b = array_alloc(ac - 1);
    if (!fill_array(ac, av, &a, &b))
        return (error());
    if (ac == 3 && a[0] > a[1])
        ft_printf("sa\n");
    else if(ac == 4)
        ft_printf("3");
    else if (ac == 5)
        ft_printf("4");
    else
        push_swap(&a, &b, ac - 1);
}