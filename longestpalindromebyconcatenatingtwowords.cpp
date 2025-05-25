class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;

        for(auto &word: words){
            freq[word]++;
        }

        // so we have store the element in hashmap
        int len = 0;
        int hascentre = 0;

        for(auto &[word,count] : freq){
            string rev = string{word.rbegin(), word.rend()};
            if(rev==word){
                len += (count/2) * 4;
                if(count%2==1) hascentre=1;
            }else if(freq.find(rev)!=freq.end()){
                // the number is not palindrome but reverse exists
                int pair = min(count, freq[rev]);
                len += pair*4;
                freq[word] = 0;
                freq[rev] = 0;
                }
            }
            if(hascentre) len += 2;
            return len;
        }
};
