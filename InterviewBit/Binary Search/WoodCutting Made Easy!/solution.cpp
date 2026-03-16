/*

WoodCutting Made Easy!

There is given an integer array A of size N denoting the heights of N trees.

Lumberjack Ojas needs to chop down B metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Ojas is only allowed to cut a single row of trees.

Ojas's machine works as follows: Ojas sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Ojas then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Ojas raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Ojas will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Ojas is ecologically minded, so he doesn't want to cut off more wood than necessary. That's why he wants to set his sawblade as high as possible. Help Ojas find the maximum integer height of the sawblade that still allows him to cut off at least B metres of wood.

NOTE:

The sum of all heights will exceed B, thus Ojas will always be able to obtain the required amount of wood.

Problem Constraints
- 1 <= N <= 10^6
- 1 <= A[i] <= 10^6
- 1 <= B <= 210^6

*/

long long get_wood(int H, int N, const vector<int>& A, const vector<long long>& pref) {
    auto it = upper_bound(A.begin(), A.end(), H);
    int idx = distance(A.begin(), it);
    
    if (idx == N) {
        return 0;
    }
    
    long long currentSum = pref[N] - pref[idx];
    long long count = N - idx;
    
    return currentSum - (count * H);
}

int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    std::sort(A.begin(), A.end());
    
    std::vector<long long> pref(N + 1, 0);
    for (int i = 0; i < N; i++) {
        pref[i + 1] = pref[i] + A[i];
    }
    
    int low = 0;
    int high = A[N - 1];
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (get_wood(mid, N, A, pref) >= B) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
