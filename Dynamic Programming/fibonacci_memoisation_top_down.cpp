#include<bits/stdc++.h>
using namespace std;

int mem[10000];

int fib(int n)
{
	// This fib function basically generates fibonacci series using memoisation optimisation technique that follows top down approach
	if(mem[n] == -1)
	{
		// This states that when true it means the subproblem has not been computed and hence it must be computed
		int res;
		if(n==0 || n==1){
			return n;
		}
		else{
			res = fib(n-1)+fib(n-2);
		}

		mem[n]=res;
	}
	return mem[n];
}

int main()
{
	// Driver function
	int n;
	cout<<"Please enter the number to compute fibonacci series: "<<endl;
	cin>>n;

	// memset here as a method fills all the elements of mem array as -1
	memset(mem,-1,sizeof(mem));

	cout<<"The computed fibonacci series is: "<<fib(n)<<endl;

	return 0;

}