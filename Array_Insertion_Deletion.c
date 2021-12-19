  #include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node  *next ;
};
void display(struct Node *head )
{
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next ;
    }
    
}
struct Node *newnode( int value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value ;
    temp->next = NULL;
    return temp ;
}
struct Node *add_end(struct Node *head , int val)
{
    struct Node *temp = newnode(val);
    if(head == NULL)
    {
        return temp ;
    }
    struct Node *ptr = head ;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        
    }
    ptr->next = temp ;
    return head ;
}
struct Node *add_begin(struct Node *head ,  int value)
{
    struct Node *temp = newnode(value);
    temp->next = head ;
    head = temp ;
    return head ;
}
struct Node *del_Index(struct Node *head , int index)
{
    int count = 0;
    struct Node *p = head ;
    struct Node *q = head->next ;
    while(count != index-1)
    {
        p = p->next ;
        q = q->next ;
        count++;
    }
    p->next = q->next ;
    free (q) ;
    return head ;
     
    
}
struct Node*del_end(struct Node *head )
{
    struct Node*temp ;
    struct Node *p = head ;
    struct Node *q = head->next ;
    while(q->next!=NULL)
    {
        p = p->next ;
        q  = q->next ;
    }
    p->next = NULL ;
    free(q);
 
    return head ;
    
}
struct Node *deletionValue(struct Node *head , int value)
{
     
    struct Node *p = head ;
    struct Node *q = head->next ;
    while(q->data != value && q->next !=NULL)
    {
        p = p->next ;
        q = q->next ;
    }
    if(  q->data == value)
    {
        p->next = q->next ;
        free(q);
    }
    else
    printf("element not found\n");
    return head;
    
}

int main()
{
        struct Node *head = NULL ;
        head = add_end(head , 10);
        head = add_end(head ,20);
        head = add_end(head ,30);
        head = add_end(head ,40);
        head = add_end(head ,50);
        printf("Linked list is:");
        display(head);
        head = del_key(head , 3);
        printf("Linked list after deletion of index 3 is\n");
        display(head);
        printf("Linked list deletion of last node\n");
        head = del_end(head);
        display(head);
        printf("deletion of node which contain value 20\n");
        head = deletionValue(head , 60);
        display(head);
        
}
