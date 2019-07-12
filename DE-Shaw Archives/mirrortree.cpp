/*Given a Two Binary Trees, write a function that
 returns true if one is mirror of other, else returns false.*/

/* Function completion */
int areMirror(Node* a, Node* b)
{
    if(a&&b)
    {
        if((a->data==b->data) && areMirror(a->left,b->right) && areMirror(a->right,b->left))
            return 1;
        return 0;
    }
    if(!a && !b)
        return 1;
     
    return 0;
}
