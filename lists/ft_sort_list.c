#include<stdio.h>
#include<stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    int             data;
}                   t_list;

int ascending(int a, int b)
{
	return (a <= b);
}

int descending(int a, int b)
{
	return (a >= b);
}

void    print_list(t_list *head)
{
    while (head)
    {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

int is_sorted(t_list *temp, int (*cmp)(int, int))
{
    t_list *lst;

    lst = temp;
    while (lst && lst->next)
    {
        if (cmp(lst->data, lst->next->data))
            lst = lst->next;
        else
            return(1);
    }
    return(0);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *temp;
    t_list  *ptr;
    int     tmp;

    temp = lst;
    ptr = lst;
    while (temp && temp->next)
    {
        if (cmp(temp->data, temp->next->data))
            temp = temp->next;
        else
        {
            tmp = temp->data;
            temp->data = temp->next->data;
            temp->next->data = tmp;
        }
        if (!temp->next && is_sorted(ptr, &descending))
            temp = ptr;
    }
    return (lst);
}

t_list  *create_node(int data)
{
    t_list *node;

    node = (t_list*)malloc(sizeof(t_list));
    node->data = data;
    node->next = NULL;
    return (node);
}

int main(void)
{
    t_list *head;
    t_list *first = create_node(-15);
    t_list *second = create_node(99);
    t_list *third = create_node(99);
    t_list *forth = create_node(65);
    t_list *fifth = create_node(-88);
    t_list *last = create_node(5);

    head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = last;

    print_list(head);
    printf("-----------------------\n");
    print_list(sort_list(head, &descending));
}
