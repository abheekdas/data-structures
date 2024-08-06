#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n)
{
	// string a -> is a string where its length is m
	// string b -> is a string where its length is n

	// We will come with a naive recursive approach where the time complexity is exponential, later we will optimise it using dynamic programming

	if(m==0 || n==0) // declaring a base case when either of the string becomes empty it should return 0
		return 0;

	if(a[m-1]==b[n-1]) // when the last character of both the string is matching then lcs will be incremented by 1 and recursive function must be called on next set of strings
		return 1+lcs(a,b,m-1,n-1);

	else // when the last character does not matches then we will take the maximum lcs of 2 subproblems where each subproblem individually goes to next set of strings
	{
		return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
	}
}

int main()
{
	string a,b;
	a = "AXYZ";
	b = "BAZ";
	int m = a.length();
	int n = b.length();
	cout<<lcs(a,b,m,n);

	return 0;
}

// The time complexity will be exponential in this case as it recursively calls and there is a chance where overlapping subproblems will be computed again and again.