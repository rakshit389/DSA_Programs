  #include<stdio.h>
 #include<stdlib.h>
 struct Node{
     int data ;
     struct Node *next ;
     struct Node *prev ;
 };
 struct Node *create(int val)
 {
     struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
     ptr->data  =  val ;
     ptr->next = NULL ;
     ptr->prev = NULL ;
 }
 void traversal(struct Node *head)
 {
     while(head!=NULL)
     {
         printf("%5d",head->data);
         head = head->next ;
     }
     
 }
 struct Node *insert_At_Begin(struct Node *head , int data)
 {
     struct Node *ptr = create(data);
     if(head == NULL)
     {
         head = ptr ;
     }
     else
     {
         ptr->next  =  head ;
         head->prev = ptr ;
         head = ptr ;
     }
     return head;
     
 }
 void Reverse_Traversal(struct Node *head)
 {
     struct Node *ptr = head ;
     while(ptr->next!=NULL)
     {
         ptr = ptr->next ;
     }
     while(ptr!=head)
     {
         printf("%5d",ptr->data);
         ptr = ptr->prev;
     }
     printf("%5d",ptr->data);
     
 }
int main()
{
    struct Node * head = NULL ;
    head = insert_At_Begin(head , 10);
    head = insert_At_Begin(head , 20 );
    head = insert_At_Begin(head , 30);
    //Forward printing of LL
    printf("Forward printing of LL\n");
    traversal(head);
    //Reverse prinitng of LL 
    printf("\nReverse printnng of LL\n");
    Reverse_Traversal(head);
    
}