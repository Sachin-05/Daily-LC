#include <bits/stdc++.h>
using namespace std;

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		cout << "value of n is " << n << endl;;
		cout << "address of n is " << &n << endl;
		int* ptr = &n;

		cout << "value of ptr is " << *ptr << endl;
		cout << "adress of ptr is" << ptr << endl;

		*ptr = 20;

		cout << "value of n is " << n << endl;
		cout << "address of n is " << &n << endl;
	}
}
