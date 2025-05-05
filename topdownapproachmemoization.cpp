#include <bits/stdc++.h>
using namespace std;

int fibonaccinumber(int n){
	// so this is the memoization technique or you can say top down approach
	
	vector <int> dp(n+1, -1);

	if(n<=1) return n;

	if(dp[n]!=-1) return dp[n];

	return fibonaccinumber(n-1) + fibonaccinumber(n-2);
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		cout << fibonaccinumber(n) << " ";
	}
	cout << endl;
}
