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
     ptr->data = val ;
     ptr->next = NULL ;
     ptr->prev = NULL;
     return ptr ;
 }
 struct Node *insertAtBegin(struct Node *head , int data)
 {
     struct Node *ptr = create(data);
     ptr->next = head ;
     ptr->prev = NULL;
     head = ptr ;
    
     return head ;
 }
 struct Node *insertAtEnd(struct Node*head , int data)
 {
     struct Node *ptr = create(data);
     struct Node*p = head ;
     while(p->next!=NULL)
     {
         p = p->next ;
     }
     p->next = ptr ;
     ptr->prev = p ;
     ptr->next = NULL;
     return head ;
 }
 struct Node *insertAtIndex(struct Node *head , int index , int data)
 {
     struct Node * ptr = create(data);
     struct Node *p = head ;
     struct Node *q = head->next ;
     int count = 0 ;
     while(count!=index-1)
     {
         p = p->next ;
         q = q->next ;
         count++;
     }
     ptr->next = p->next ;
     p->next = ptr ;
     ptr->prev = p ; 
     q->prev = ptr ;
      return head ;
     
 }
 void traversal(struct Node *head)
 {
     while(head!=NULL)
     {
         printf("%5d",head->data);
         head = head->next ;
     }
 }
 struct Node *del_At_First(struct Node *head)
 {
     struct Node *temp = head ;
     head = head->next ;
     head->prev = NULL ;
     free(temp);
     return head ;
 }
 struct Node * del_At_End(struct Node * head)
 {
     struct Node *ptr1 = head ;
     struct Node *ptr2 = head->next ;
     while(ptr2->next != NULL)
     {
         ptr1 = ptr1->next ;
         ptr2 = ptr2->next ;
     }
     ptr1->next = NULL ;
     free(ptr2);
     return head ;
 }
 struct Node *del_At_Index(struct Node *head , int index)
 {
     struct Node *ptr1 = head ;
     struct Node *ptr2 = head->next ;
     int count = 0 ;
     while(count != index-1)
     {
         ptr1 = ptr1->next ;
         ptr2 = ptr2->next ;
         count++;
         
     }
     ptr1->next =   ptr2->next ;
     struct Node *temp = ptr2->next ;
     temp->prev = ptr1 ;
     free(ptr2);
     return head ;
 }
 struct Node *del_Search_Key(struct Node *head , int val)
 {
     struct Node *ptr1 = head ;
     struct Node *ptr2 = head->next ;
     while(ptr2->data != val && ptr2->next != NULL)
     {
         ptr1 = ptr1->next ;
         ptr2 = ptr2->next ;
     }
     if(ptr2->data == val){
         ptr1->next = ptr2->next ;
         struct Node *temp = ptr2->next ;
         temp->prev = ptr1 ;
         free(ptr2);
     }
     else
     printf("\n Value not found in ll\n");
     return head ;
 }
 int main()
 {
     struct Node *head = NULL ;
     head = insertAtBegin(head , 500);
     head = insertAtBegin(head , 400);
     head = insertAtBegin(head , 300);
     head = insertAtBegin(head , 200);
     head = insertAtBegin(head , 100);
     head = insertAtBegin(head , 50 );
     head = insertAtEnd( head , 600);
     head = insertAtIndex(head , 2 , 1000);
     traversal(head);
     //Deleting first Node of ll
     head = del_At_First(head );
     printf("\n   After deleting first node of  ll\n");
     traversal(head);
     //Deleting last Node of ll
     head = del_At_End(head);
     printf("\n  After deleting last node of ll\n");
     traversal(head);
     //Deleting node at index i
     head = del_At_Index(head ,2);
     printf("\n After deleting node at index i\n");
     traversal(head);
     //Deleting node by finding value 
     head = del_Search_Key(head , 4000);
     printf("\n After deleting node by finding value\n");
     traversal(head);
     return 0;
 }
