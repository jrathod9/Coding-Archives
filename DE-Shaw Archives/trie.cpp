/* Trie is an efficient information retrieval 
data structure. Use this data structure to store
Strings and search strings. Your task is to use
TRIE data structure and search the given string A.
If found print 1 else 0.*/

/* Test Case : 	Input:
				1
				8
				the a there answer any by bye their
				the
				Output:
				1 */

/* Simple solution using map  (NOTE :Try using Trie)
Link : https://www.geeksforgeeks.org/trie-insert-and-search/ 
*/ 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    map<string,int> count;
	    while(n--)
	    {
	        cin>>s;
	        count[s]=1;
	    }
	    cin>>s;
	    cout<<count[s]<<endl;
	}
	return 0;
}