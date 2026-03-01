class Solution {
public:
    int minPartitions(string n) {
        char maxdigit = *max_element(begin(n), end(n));

        return maxdigit - '0';
    }
};
