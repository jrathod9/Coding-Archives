/*Reversing a doubly linked list */
/* Function completion */
/* Link : https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/ */

void reverse(Node **head_ref)
{
  // Your code goes here
  Node * temp = NULL , *curr = *head_ref;
  while(curr!=NULL)
  {
      temp = curr->prev;
      curr->prev = curr->next;
      curr->next = temp;
      curr = curr->prev;
  }
  if(temp!=NULL)
    *head_ref = temp->prev;
}