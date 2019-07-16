/* You do  2 operations:

If a number is odd, you either add 1 to it or subtract 1 from it.
If a number is even, you divide the number by 2.
Get to 1 in least number of steps. 

Input:
The first line of input contains T, the number of testcases. T testcases follow. Each testcase contains one line of input containing number N.

Output:
For each testcase, in a new line, print the minimum number of steps.

Link : https://practice.geeksforgeeks.org/contest-problem/transmutation0001/0/ 
*/

#include<bits/stdc++.h>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define loop(i,init,lim) for(int i = init ; i < lim ; i++)
#define l long int
#define ll long long 
#define write(x) cout<<(#x)<<" is "<<x<<endl;
#define sorted(a) sort(a.begin(),a.end())
using namespace std;

int mini = INT_MAX;

void transmute(long long int n,int steps)
{
    if(n == 1)
    {
        if(steps<mini)
            mini = steps;
        return;
    }
    steps++;
    if(n%2 == 0)
    {
        n/=2;
        transmute(n,steps);
    }
    else
    {
        transmute(n-1,steps);
        transmute(n+1,steps);
    }
}

int main()
{
	   int t;
	   cin>>t;
	   while(t--)
	   {
	       mini = INT_MAX;
	       long long int n;
	       cin>>n;
	       int step = 0;
	       transmute(n,step);
	       
	       cout<<mini<<endl;
	   }
	return 0;
}
