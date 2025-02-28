#include <bits/stdc++.h>
using namespace std;

string findlcs(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();

	vector <vector<int>> dp(len1+1, vector<int>(len2+1, 0));
	// as the strings can be empty as well

	for(int i=1; i<len1; ++i){
		for(int j=1; j<len2; ++j){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string lcs;

	int i=len1, j=len2;

	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			lcs.push_back(s1[i-1]);
			i--;
			j--;
		}else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}else{
			j--;
		}
	}

	reverse(lcs.begin(), lcs.end());
	return lcs;
}

string shortcommonsubseq(string s1, string s2){
	int l1 = s1.length();
	int l2 = s2.length();
	string lcs = findlcs(s1, s2);
	string ans = "";

	int p1 = 0, p2=0;

	for(auto c : lcs){
		while(c!=s1[p1]){
			ans+= s1[p1++];   // add all non LCS char from string 1
		}
		while(c!=s2[p2]){
			ans += s2[p2++];   // add all non LCS char from string 2
		}

		ans += c;
		p1++;
		p2++;
	}

	ans += s1.substr(p1) + s2.substr(p2);
	return ans;
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		string s1, s2;
		cin >> s1 >> s2;

		// here we have to take care of both the strings and want to make sure 
		// cabac abc
		cout << shortcommonsubseq(s1, s2) << " ";
	}
	cout << endl;
}
