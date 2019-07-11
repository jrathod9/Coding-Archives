/*The reverse and add function starts with a number, 
reverses its digits, and adds the reverse to the
original. If the sum is not a palindrome, repeat
this procedure until it does.
Write a program that takes number and gives the resulting
palindrome (if one exists). If it took more than 1,000
iterations (additions) or yield a palindrome that is 
greater than 4,294,967,295, assume that no palindrome exist for the given number.*/
/* Test Cases : Input : 195
				Output : 9339

				Input : 265
				Output: 45254

				Input : 196
				Output : No palindrome exist 
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXX 4294967295

long long int reverse(long long int n)
{
	long long int num = 0;
	while(n>0)
	{
		num*=10;
		num+=n%10;
		n/=10;
	}
	return num;
}
bool palindrome(long long int n)
{
	if(n == reverse(n))
		return true;
	else
		return false;
}
int main()
{
	long long int n;
	cin>>n;
	while(1)
	{
		long long int rev = reverse(n);
		long long int sum = n+rev;
		n = sum;
		if(sum>MAXX)
		{
			cout<<"No palindrome"<<endl;
			break;
		}
		if(palindrome(sum))
		{
			cout<<sum;
			break;
		}
	}
}