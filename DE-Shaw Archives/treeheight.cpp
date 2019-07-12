/*Given a binary tree, find height of it.
        1 
      /   \
    10     39
   /
  5
The above tree has a height of 3.
Note: Height of empty tree is considered 0.
*/
/* Function completion question (complete function height()) */

int maxheight = 0;
void findheight(Node *node, int level)
{
    if(node->right == NULL && node->left == NULL)
    {
        if(level>maxheight)
            maxheight = level;
        return;
    }
    if(node->right != NULL)
        findheight(node->right,level+1);
    if(node->left != NULL)
        findheight(node->left,level+1);
    
}
int height(Node* node)
{
    maxheight = 0;
    if(node == NULL)
        return 0;
    int level = 1;
   findheight(node,level);
   return maxheight;
}