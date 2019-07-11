/*Given a binary tree, where every node value
 is a number. Find the sum of all the numbers which 
 are formed from root to leaf paths. */
/*
		6
	  /   \
	 3	   5
    / \		\
   2   5   	 4
      / \
     7   4
  There are 4 leaves, hence 4 root to leaf paths:
  Path                      Number
  6->3->2                   600+30+2=632
  6->3->5->7                6000+300+50+7=6357
  6->3->5->4                6000+300+50+4=6354
  6->5>4                    600+50+4=654   
  Answer = 632 + 6357 + 6354 + 654 = 13997
 */
/* Required to complete the function treePathsSum()*/


long long res = 0;
void solve(Node *root, int data)
{
    if(root->right == NULL && root->left == NULL)
    {
        res+=data;
        return;
    }
    if(root->right)
    {
        solve(root->right,data*10 + (root->right)->data);
    }
    if(root->left)
    {
        solve(root->left,data*10 + (root->left)->data);
    }
}
long long treePathsSum(Node *root)
{
    //Your code here
    res = 0;
    solve(root,root->data);
    return res;
}
