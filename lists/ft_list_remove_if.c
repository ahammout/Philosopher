#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void    print_list(t_list *head)
{
    while (head)
    {
        printf("%s\n", head->data);
        head = head->next;
    }
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *ft_free;
    t_list  *temp;
    t_list  *tmp;

    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
            ft_free = (*begin_list);
            *begin_list = (*begin_list)->next;
            free(ft_free);
    }
    tmp = *begin_list;
    while (tmp && (tmp)->next)
    {
        if (cmp((tmp)->next->data, data_ref) == 0)
        {
            temp = (tmp)->next;
            tmp->next = (tmp)->next->next;
            free(temp);
        }
        else
            tmp = tmp->next;
    }
}


int main(void)
{
    // declaring linked list.
    t_list *head;
    t_list  *first;
    t_list  *second;
    t_list  *third;
    t_list  *last;

    //allocation dynamique of list.
    first = (t_list*)malloc(sizeof(t_list));
    second = (t_list*)malloc(sizeof(t_list));
    third = (t_list*)malloc(sizeof(t_list));
    last = (t_list*)malloc(sizeof(t_list));

    //constructList and fill list.
    head = first;
    first->data = "world";
    first->next = second;
    second->data = "world"; 
    second->next = third;
    third->data = "world";
    third->next = last;
    last->data = "world";
    last->next = NULL;

    // printing list.
    print_list(head);
    ft_list_remove_if(&head, "world", strcmp);
    printf("===========\n");
    print_list(head);
    return (0);
}