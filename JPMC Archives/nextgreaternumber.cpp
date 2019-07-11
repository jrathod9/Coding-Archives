/* Given a number n, find the smallest number that has
 same set of digits as n and is greater than n. If n is the
 greatest possible number with its set of digits, 
 then print “not possible”. */
/* Test Cases : Input:  n = "218765"
				Output: "251678"

				Input:  n = "1234"
				Output: "1243"

				Input: n = "4321"
				Output: "Not Possible"

				Input: n = "534976"
				Output: "536479"
Link : https://www.geeksforgeeks.org/find-next-greater-number-set-digits/ 
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
	    int arr[n];
	    for(int i = 0 ; i < n ; i++)
	   {
	        cin>>arr[i];
	   }
	   
	   if(arr[n-1]>arr[n-2])
	   {
	       int tempp = arr[n-1];
	       arr[n-1] = arr[n-2];
	       arr[n-2] = tempp;
	       for(int i = 0 ; i< n ; i++)
	        cout<<arr[i]<<" ";
	       
	       cout<<endl;
	   }
	   else
	   {
	       vector<int> temp;
	       int curr = n-1;
	       while(arr[curr]<arr[curr-1] && curr>=0)
	       {
	           temp.push_back(arr[curr]);
	            curr--;
	       }
	       if(curr<0)
	       {
	           cout<<"Not Possible"<<endl;
	       }
	       else
	       {
	           temp.push_back(arr[curr]);
	           for(int i = 0 ; i < temp.size() ; i++)
	           {
	               if(temp[i] > arr[curr-1])
	               {
	                   int tempp = arr[curr-1];
	                   arr[curr-1] = temp[i];
	                   temp[i] = tempp;
	                   break;
	               }
	           }
	           for(int i = 0 ; i < curr ; i++)
	            cout<<arr[i]<<" ";
	            
	            sort(temp.begin(),temp.end());
	           for(int i = 0 ; i < temp.size() ; i++)
	            cout<<temp[i]<<" ";
	           cout<<endl;
	       }
	   }
	}
	return 0;
}