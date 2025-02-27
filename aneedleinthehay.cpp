#include <bits/stdc++.h>
using namespace std;

vector<string> gereratesubseq(string s, string current){
	vector<string> res;

	if(s.empty()){
		res.push_back(current);
		return res;
	}

	// now we have to incude the string with first char 
	vector <string> include = gereratesubseq(s.substr(1), current + s[0]);

	// now we don't have to include the string with first char
	vector <string> exclude = gereratesubseq(s.substr(1), current);

	// now we have to take care off the result vector of our storage checking
	// below is just merging our finding array

	res.insert(res.end(), include.begin(), include.end());
	res.insert(res.end(), exclude.begin(), exclude.end());

	return res;
}

vector <string> subseq(string s){
	string curr = "";
	return gereratesubseq(s, curr);
}

int main(){
	// we need to have printing all the subsequences;
	string s;
	cin >> s;
	vector <string> allsubseq = subseq(s);

	int count = 0;

	string needle;
	cin >> needle;
	for(auto it : allsubseq){
		if(it == needle){
			count++;
		}
	}
    cout << count << endl;
}
