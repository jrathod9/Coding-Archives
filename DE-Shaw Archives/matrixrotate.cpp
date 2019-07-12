/* Given a square matrix mat[][] of size N x N. 
The task is to rotate it by 90 degrees in anti-clockwise 
direction without using any extra space.

Input:
The first line of input contains a single integer 
T denoting the number of test cases. Then T test 
cases follow. Each test case consist of two lines.
 The first line of each test case consists of an integer N, 
 where N is the size of the square matrix.
 The second line of each test case contains N x N 
 space separated values of the matrix mat.

Output:
Corresponding to each test case, in a new line, print the rotated array.
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
        int arr[n][n];
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                cin>>arr[j][i];             //take input as transform of matrix
            }
        }
        
        for(int i = n-1; i >=0 ; i--)       //print from bottom to top
        {
            for(int j = 0 ; j< n ; j++)
            {
                cout<<arr[i][j]<<" ";           
            }
        }
        cout<<endl;
    }
	return 0;
}