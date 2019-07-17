/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) 
In-Place. The left and right pointers in nodes are to be used as
previous and next pointers respectively in converted DLL. The order of nodes 
in DLL must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
The tree is
                         10
                       /    \
                     20      30
                   /    \
                 40      60

So, DLL would be 40<=>20<=>60<=>10<=>30.
*/

vector<Node *> v;
void infix(Node * root)
{
    if(root == NULL)
        return;
    infix(root->left);
    v.push_back(root);
    infix(root->right);
}
void bToDLL(Node *root, Node **head_ref)
{
    v.clear();
    infix(root);
    
    v[0]->left = NULL;
    for(int i = 0 ; i< v.size()-1 ; i++)
    {
        v[i]->right = v[i+1];
        v[i+1]->left = v[i];
    }
    v[v.size()-1]->right = NULL;
    * head_ref = v[0]; 
}
