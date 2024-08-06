#include <bits/stdc++.h>
using namespace std;

// solving longest common subsequence problem trying to recall
int dp[10000][10000]; // declaring this as dp array with 1000000.

int lcs(string a, string b, int m, int n) // The time complexity for this approach is exponential as there is a chance overlapping subproblem is recomputed as function overhead
{
	// here we have 2 strings a and b. a is having m as its length and b is having n as its length
	// we will be trying to solve this problem recursively

	//thinking of the base case?
	if(m == 0 || n == 0) // if either of the string becomes 0 in size then lcs will be 0
			return 0;

	if(a[m-1]==b[n-1]) // when the last characters of both the strings are same then we will call the recursive function
		return 1+lcs(a,b,m-1,n-1); // we will update the pointers for both of the string to second last character.

	else // when the last character of both the strings are not matching then what?
	{
		return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1)); // we will take the maximum value of the subtree problem, where this subtree has 2 nodes one where string a is reduced by 1 character and string b is reduced by 1 character.
	}			
}

int lcs_dp_optimised(string a, string b, int m, int n) // here we will be using the memoisation technique to optimise the solution.
{
	if (dp[m][n]!=-1)
		return dp[m][n]; // here we are stating if a subproblem has been recalculated directly return it without the need to recompute it.

	if (m==0 || n==0) // the base case when either of the strings length become 0
		dp[m][n] = 0;

	else
	{
		if(a[m-1]==b[n-1]) // when the last characters of both the strings are equivalent then we will update the pointers of both the strings by -1 and also add 1, and recall the lcs function with updated string pointers
			dp[m][n] = 1+lcs(a,b,m-1,n-1);

		else
		{
			// if the last characters do not match then in this case we will take the maximum lcs of the subproblems and each subproblem will be 1 reduced pointer position of the string
			dp[m][n] = max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
		}
	}
	return dp[m][n];
}

int main()
{
	string a = "AB";
	int m = a.length();
	string b = "XYABZJ";
	int n = b.length();

	memset(dp,-1,sizeof(dp)); // initialising all the elements of dp array as -1


	cout<<lcs_dp_optimised(a,b,m,n);

	return 0;
}