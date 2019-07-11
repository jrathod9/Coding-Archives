/* Given an array of digits (2-9) ,find 
all possible combination of words fromed from
a mobile keypad using those digits
in given order itself */
/*	2 - ABC	
	3 - DEF
	4 - GHI
	5 - JKL
	6 - MNO
	7 - PQRS
	8 - TUV
	9 - WXYZ
*/
/* Test Case : 	Input : 2 3
				Output : AD AE AF BD BE BF CD CE CF

Link : https://www.techiedelight.com/find-possible-combinations-words-formed-from-mobile-keypad/ 
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> hashed;

void solve(int arr[] , string res ,int count , int n)
{
	if(count == n)
	{
		cout<<res<<" ";
		return;
	}
	for(int i = 0 ; i < hashed[arr[count]].size() ; i++)
	{
		solve(arr,res+hashed[arr[count]][i],count+1,n);
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0 ; i<n ; i++)
		cin>>arr[i];	
	hashed.push_back("");
	hashed.push_back("");
	hashed.push_back("abc");
	hashed.push_back("def");
	hashed.push_back("ghi");
	hashed.push_back("jkl");
	hashed.push_back("mno");
	hashed.push_back("pqrs");
	hashed.push_back("tuv");
	hashed.push_back("wxyz");

	string res = "";

	solve(arr,res,0,n);
}