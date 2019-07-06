/*Given a value V. You have to make change for V cents,
given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins.
Find the minimum number of coins to make the change.
*/

/* ---- NAIVE RECURSIVE APPROACH ---- */
#include<bits/stdc++.h>
using namespace std;

long int minsum = INT_MAX;

void mincoins(long int coins[],long int n,long int remaining,long int sum)
{
    if(remaining == 0)
    {
        if(sum<minsum)
            minsum = sum;
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(coins[i]<=remaining)
            {
                mincoins(coins,n,remaining-coins[i],sum+1);
            }
        }
    }
        
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int v,n;
        cin>>v>>n;
        long int coins[n];
        for(long int i  = 0; i < n ; i++)
            cin>>coins[i];
        sort(coins,coins+n,greater<int>());
        mincoins(coins,n,v,0);
	    cout<<minsum<<endl;
	    minsum = INT_MAX;
    }
	
	return 0;
}

/* ---- DP solution ---- */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int v,n;
        cin>>v>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int dp[v+1];
        dp[0]=0;
        for(int i=1;i<=v;i++)
        dp[i]=INT_MAX;
      
        for(int i=1;i<=v;i++){
            for(int j=0;j<n;j++){
                if(a[j]<=i){
                    if(dp[i-a[j]]!=INT_MAX){
                    dp[i]=min(dp[i-a[j]]+1,dp[i]);
                       
                    }
                }
            }
        }
        if(dp[v]!=INT_MAX)
        cout<<dp[v]<<endl;
        else
        cout<<-1<<endl;
    }
    return 0;
}