/* Given a Binary Search Tree (BST) and a
 range l-h(inclusive), count the number
  of nodes in the BST that lie in the given range.

  Test case : 	input:
				2
				6
				10 5 50 1 40 100
				5 45
				5
				5 6 7 4 3
				2 8

				Output:
				3
				5

Function completion (complete function getCountOfNodes() )				
*/

int countt = 0;
void countnodes(Node * root,int l,int h)
{
    if(root->data >= l && root->data <= h)
        countt++;
    
    if(root->right)
        countnodes(root->right , l,h);
    if(root->left)
        countnodes(root->left,l,h);
}
int getCountOfNode(Node *root, int l, int h)
{
    countt = 0;
  countnodes(root,l,h);
  return countt;
}