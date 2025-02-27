#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	// this is the base condition
	// and euclidean algorithm

	if(b==0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int test;
	cin >> test;
	while(test--){
		int a, b;
		cin  >> a >> b;
		cout << gcd(a,b) << endl;
	}
}
