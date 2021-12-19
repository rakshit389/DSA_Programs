 #include<stdio.h>
 #include<stdlib.h>
 struct Node {
     int data ;
     struct Node * next ;
 };
 struct Node *create(int val)
 {
     struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
     ptr->data = val ;
     return ptr ;
 }
 struct Node *insert_At_First(struct Node *tail , int data)
 {
     struct Node*ptr = create(data);
     if(tail==NULL)
     {
         ptr->next = ptr ;
         tail = ptr ;
         tail->next = ptr ;
     }
     else
     {
         ptr->next = tail->next ;
         tail->next = ptr ;
     }
     return tail ;
 }
 struct Node *insert_At_End(struct Node *tail , int data)
 {
     struct Node *ptr = create(data);
     if(tail == NULL )
     {
         ptr->next = ptr ;
         tail = ptr ;
         tail->next = ptr ;
     }
     else
     {
        ptr->next = tail->next;
        tail->next = ptr ;
        tail = ptr ;
         
     }
     return tail ;
 }
 void traversal(struct Node *tail)
 {
     struct Node *ptr = tail->next ;
     do{
         printf("%5d",ptr->data);
         ptr = ptr->next ;
     }while(ptr!=tail);
     printf("%5d",ptr->data);
 }
 struct Node *del_At_First(struct Node *tail)
 {
     struct Node * temp = tail->next ;
     tail->next = temp->next ;
     free(temp);
     return tail ;
 }
 struct Node *del_At_End(struct Node *tail)
 {
     if(tail==NULL)
     return tail ;
     if(tail->next==tail)
     {
        free(tail);
        tail = NULL ;
        return tail ;
     }
     struct Node *temp = tail->next ;
     while(temp->next != tail)
     {
         temp = temp->next ;
     }
     temp->next = tail->next ;
     free(tail);
     tail = temp ;
     return tail ;
     
     
 }
 struct Node *del_At_Index(struct Node *tail ,  int index)
 {
     struct Node *ptr1 = tail->next ;
     struct Node *ptr2 = ptr1->next ;
     int count =  0 ;
     while(count!=index-1)
     {
        ptr1 = ptr1->next ;
        ptr2 = ptr2->next ;
        count++;
     }
     ptr1->next = ptr2->next ;
     free(ptr2);
     return tail ;
     
 }
 struct Node *del_Search_Key(struct Node *tail , int val)
 {
     struct Node *ptr1 = tail->next ;
     struct Node *ptr2 = ptr1->next ;
     while(ptr2->data != val && ptr2->next != NULL)
     {
         ptr1 = ptr1->next ;
         ptr2 = ptr2->next ;
     }
     if(ptr2->data==val)
     {
         ptr1->next = ptr2->next ;
         free (ptr2);
     }
     return tail ;
 }
 int main()
 {
     struct Node *tail = NULL ;
     tail = insert_At_End(tail , 10);
     tail = insert_At_End(tail , 20);
     tail = insert_At_End(tail , 30);
     tail = insert_At_End(tail , 40);
     tail = insert_At_End(tail , 50);
     tail = insert_At_End(tail , 60);
     tail = insert_At_End(tail , 70);
     printf("circular linked lis is : \n");
     traversal(tail);
     //Deleting first node of  ll
     printf("\nAter deleting first node\n");
     tail  = del_At_First(tail);
     printf("\n");
     traversal(tail);
     //Deleting last node of ll
     printf("\nAter deleting last node\n");
     tail = del_At_End(tail);
     printf("\n");
     traversal(tail);
     //Deleting node bitween ll 
     tail = del_At_Index(tail , 3);
     printf("\nAfter deleting intermediate node\n");
     printf("\n");
     traversal(tail);
     //Deleting node by searching key value
     tail = del_Search_Key(tail , 30);
     printf("\nAfter deleting node by searching key value\n");
     printf("\n");
     traversal(tail);
     
 }