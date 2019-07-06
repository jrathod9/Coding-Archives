//Knapsack problem
/*Given weights and values of n items, put these items in a knapsack of
capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] 
which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the
maximum value subset of val[] such that sum of the weights of this 
subset is smaller than or equal to W. You cannot break an item,
either pick the complete item, or don’t pick it (0-1 property). */

/* Test case : 	n = 4 
				W = 7
				values = 1 4 5 7
				weight = 1 3 4 5
	Result : 9 ( selecting 3 and 4 kg weights )
*/

// Link : https://www.youtube.com/watch?v=8LusJS5-AGo

#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}	

int knapsack(int W, int weight[] , int value[] , int n)
{
	int dp[n+1][W+1];

	for(int i = 0 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= W ; j++)
		{
			if( i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if(weight[i-1] > j)		//if current weight cant be fit into the given weight sack 
			{
				dp[i][j] = dp[i-1][j];

			}
			else
			{	
				dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]] , dp[i-1][j]);	
				//max (select this + max of previous remaining weight , dont select this & max of this weight )
			}
		}
	}
	return dp[n][W];
}

int main()
{
	int n;		
	cin>>n;
	int value[n],weight[n];		// values and weights
	int W;						//max weight

	cin>>W;

	for(int i = 0 ; i < n ; i++)
		cin>>value[i];
	for(int i = 0 ; i < n ; i++)
		cin>>weight[i];

	cout<<knapsack(W,weight,value,n);

}