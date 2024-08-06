#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b)
{
	// we will be using tabulation method (bottom up apporach) to build the solution

	int m = a.length(); // the length of string a
	int n = b.length(); // the length of string b

	// declaring a dp array to store the results
	int dp[m+1][n+1];

	for(int i=0;i<=m;i++) // making the first row as 0 for the empty string
		dp[i][0] = 0;

	for(int j=0;j<=n;j++) // making the first column as 0 for the empty string
		dp[0][j] = 0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main()
{
	string a = "AXYZ";
	string b = "BAZ";

	int m = a.length();
	int n = b.length();

	cout<<lcs(a,b);

	return 0;
}