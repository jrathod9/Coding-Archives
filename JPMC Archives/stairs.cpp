/*Given an array consisting of the maximum jump possible
from that position, find the minimum number of jumps
required to take us to the end of the array .*/
/*	Test case:	n = 11
				arr = 1 3 5 8 9 2 6 7 6 8 9
				n = 6
				arr = 1 4 3 2 6 7
	Output 	:	3 ( 1 --> 3 --> 8/9 --> 9)
				2 (1 --> 4 --> 7)
(If value is 0 , no jump can be done)

Link : https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
 */

#include<bits/stdc++.h>
using namespace std;

long int jumps(long int a[],int n)
{
    long int maxcur=0,k=0,maxnext,g=0;
    if(a[0]!=0)
    {
    while(maxcur<n)
    {
        
        if(maxcur+a[maxcur]>=n-1)
      	{
          g++;
          return g;
	    }
      for(int i=maxcur+1;i<=maxcur+a[maxcur];i++)
      {
          if(a[i]+i>k)
          {
              k=a[i]+i;
              maxnext=i;
          }
      }
        
        
      if(k==0)
      return -1;
      
      maxcur=maxnext;
     
      g++;  
      k=0;
    }
        return g;
    }
    
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    
    {
        long int n;
        cin>>n;
        long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<jumps(a,n)<<endl;
    }
	//code
	return 0;
}