#include<bits/stdc++.h>
using namespace std;

int mem[1000][1000];

int lcs(string s1, string s2, int m, int n)
{
	// string s1 and its length is m
	// string s2 and its length is n

	// declaring a case where we have already computed the subproblem then we will directly return the result.
	if(mem[m][n]!=-1)
		return mem[m][n];

	if(m==0 || n==0) // declaring a base case where either of the string becomes empty
		mem[m][n] = 0;

	else
	{
		if(s1[m-1]==s2[n-1]) // when the last character of both the string matches then we increment lcs by 1 and reduce both strings by 1
		mem[m][n] = 1 + lcs(s1,s2,m-1,n-1);

		else // this is the case when last characters of both strings don't match then we take the maximum lcs of 2 subproblems where these individual subproblems is reducing strings by 1 individually
		{
			mem[m][n] = max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
		}
	}
	return mem[m][n];
}

int main()
{
	string a = "AXYZ";
	string b = "BAZ";
	int m = a.length();
	int n = b.length();

	memset(mem,-1,sizeof(mem)); // setting all the values of mem array as -1.

	cout<<lcs(a,b,m,n);

	return 0;
}

// The time complexity in this case will be O(n^2)