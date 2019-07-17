/*
Given a singly linked list: A0→A1→…→An-1→An,
reorder it to: A0→An→A1→An-1→A2→An-2→…

Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

It is recommended do this in-place without altering the nodes' values.

Input:

In this problem, method takes one argument: Address of the head of the linked list.
The function should not read any input from stdin/console.
The node structure has a data part which stores the data and a
next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, 
this method will be called individually.

Input:

2
3
1 2 3
4
1 7 3 4

Output:

1 3 2
1 4 7 3

*/

void reorderList(Node* head) 
{
    stack<Node *> s;
    Node * t = head;
    while(t!=NULL)
    {
        s.push(t);
        t = t->next;
    }
    
    t = head;
    int count = 0;
    int len = s.size();
    while(count<=len/2)
    {
        count++;
        s.top()->next = t->next;
        t->next = s.top();
        s.pop();
        t = (t->next)->next;
    }
    
    t->next = NULL;
}
