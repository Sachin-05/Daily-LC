class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
    vector <int> freqdidgit(10);
    int n = digits.size();

	for(int i=0; i<n; ++i){
		freqdidgit[digits[i]]++;
	}

	// so now we have all the count
	vector <int> res;

	for(int i=1; i<=9; ++i){
		if(freqdidgit[i]==0){
			continue;
		}
		freqdidgit[i]--;
		for(int j=0; j<=9; ++j){
			if(freqdidgit[j]==0){
				continue;
			}
			freqdidgit[j]--;
			for(int k=0; k<=8; k+=2){
				if(freqdidgit[k]==0){
					continue;
				}
				res.push_back(i*100 + j*10 + k);
			}
			freqdidgit[j]++;
		}
		freqdidgit[i]++;
	}
	return res;
    }
};
