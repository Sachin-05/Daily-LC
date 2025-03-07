class Solution {
public:

    bool prime(int i){
        for(int x=2; x*x <= i; x++){
            if(i%x==0){
                return false;
            }
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        //brute force
        vector <int> primevec;
        
        if(left==1){
            left = 2;
        }
        
        for(int i=left; i<=right; ++i){
            if(prime(i)){
                primevec.push_back(i);
            }
        }

        int first = -1, second = -1;
        int minidiff = INT_MAX;

        for(int i=0; i<primevec.size()-1; ++i){
            if((primevec[i+1]-primevec[i]) < minidiff){
                minidiff = min(primevec[i+1]-primevec[i], minidiff);
                first = primevec[i];
                second = primevec[i+1];
            }
        }
        return {first, second};
    }
};
