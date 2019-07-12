/* Given a sorted array A, size N, of integers;
 every element appears twice except for one. 
 Find that element in linear time complexity 
 and without using extra memory.

Test Case:  Input:
            1
            11
            1 1 2 2 3 3 4 50 50 65 65
            Output:
            4

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        long int arr[n];
        for(long int i = 0 ; i<n ; i++)
            cin>>arr[i];
        
        if(n == 1)
        {
            cout<<arr[0]<<endl;
            continue;
        }
         int count = 1;   
        for(long int i = 1 ; i<n ; i++)
        {
            if(arr[i] == arr[i-1])
            {
                if(count == 1)
                    count = 2;
            }
            else if(arr[i] != arr[i-1] && count == 1)
            {
                cout<<arr[i-1]<<endl;
                continue;
            }
            else
                count = 1;
        }
        if(arr[n-1]!=arr[n-2])
            cout<<arr[n-1]<<endl;
    }
	return 0;
}