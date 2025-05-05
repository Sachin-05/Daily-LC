#include <bits/stdc++.h>
using namespace std;

int fibonaccinumber(int n){
	// so this is the memoization technique or you can say top down approach

	vector <int> dp(n+1, -1);

	if(n<=1) return n;

	if(dp[n]!=-1) return dp[n];

	return fibonaccinumber(n-1) + fibonaccinumber(n-2);

	// so now let's do it with the help of understanding of the outset global
}

int fibonaccinumbertabulation(int n){
	vector <int> dp(n+1);

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2; i<=n; ++i){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		cout << fibonaccinumber(n) << " ";
		cout << fibonaccinumbertabulation(n) << " ";
	}
	cout << endl;
}
