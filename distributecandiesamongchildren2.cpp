class Solution {
public:
typedef long long ll;

ll choose2(ll n) {
    if (n < 0) return 0;
    return n * (n - 1) / 2;
}

// Function to compute S(x) = C(x + 2, 2)
ll S(ll x) {
    if (x < 0) return 0;
    return (x + 2) * (x + 1) / 2;
}

    long long distributeCandies(int n, int limit) {
        // so we have to found out all the pnc
        ll res = S(n);
    res -= 3 * S(n - limit - 1);
    res += 3 * S(n - 2 * limit - 2);
    res -= S(n - 3 * limit - 3);
    return res;
    }
};
