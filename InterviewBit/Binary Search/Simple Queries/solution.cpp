/*

Simple Queries

You are given an array A having N integers.

You have to perform the following steps in a given order.

1) generate all subarrays of A.

2) take the maximum element from each subarray of A and insert it into a new array G.

3) replace every element of G with the product of their divisors mod 1e9 + 7.

4) sort G in descending order

You now need to perform Q queries

In each query, you are given an integer K, where you have to find the Kth element in G.

NOTE : Your solution will run on multiple test cases so do clear global variables after using them.

*/

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXV = 1e5 + 5;

int num_divisors[MAXV];
bool precomputed = false;

void precompute() {
    if (precomputed) return;
    for (int i = 1; i < MAXV; i++) {
        for (int j = i; j < MAXV; j += i) {
            num_divisors[j]++;
        }
    }
    precomputed = true;
}

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll get_prod_divisors(int n) {
    ll d = num_divisors[n];
    if (d % 2 == 0) {
        return power(n, d / 2);
    } else {
        return (power(n, d / 2) * (ll)sqrt(n)) % MOD;
    }
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    precompute();
    int N = A.size();
    vector<ll> L(N), R(N);
    stack<int> s;

    for (int i = 0; i < N; i++) {
        while (!s.empty() && A[s.top()] < A[i]) s.pop();
        L[i] = s.empty() ? i : i - s.top() - 1;
        s.push(i);
    }
    while (!s.empty()) s.pop();

    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && A[s.top()] <= A[i]) s.pop();
        R[i] = s.empty() ? (N - 1 - i) : (s.top() - i - 1);
        s.push(i);
    }

    map<ll, ll, greater<ll>> counts;
    for (int i = 0; i < N; i++) {
        ll freq = (L[i] + 1) * (R[i] + 1);
        ll val = get_prod_divisors(A[i]);
        counts[val] += freq;
    }

    vector<pair<ll, ll>> sortedG;
    ll total = 0;
    for (auto const& [val, freq] : counts) {
        total += freq;
        sortedG.push_back({val, total});
    }

    vector<int> results;
    for (int k_val : B) {
        ll K = k_val;
        auto it = lower_bound(sortedG.begin(), sortedG.end(), make_pair(0LL, K),
                 [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.second < b.second;
        });
        
        if (it == sortedG.end()) results.push_back(-1);
        else results.push_back((int)it->first);
    }

    return results;
}
