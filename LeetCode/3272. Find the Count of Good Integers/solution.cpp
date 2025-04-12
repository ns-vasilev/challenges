/*

3272. Find the Count of Good Integers

You are given two positive integers n and k.

An integer x is called k-palindromic if:

x is a palindrome.
x is divisible by k.
An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

Return the count of good integers containing n digits.

Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

*/

class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            std::unordered_set<std::string> m;
            
            int b = std::pow(10, (n - 1) / 2);
            int skip = n & 1;
    
            for (int i = b; i < b * 10; ++i) {
                std::string s = std::to_string(i);
                s += std::string(s.rbegin() + skip, s.rend());
    
                long long palindrom_integer = stoll(s);
    
                if (palindrom_integer % k == 0) {
                    std::sort(s.begin(), s.end());
                    m.emplace(s);
                }
            }
    
            std::vector<long long> factorial(n + 1, 1);
    
            long long ans = 0;
    
            for (int i = 1; i <= n; ++i) {
                factorial[i] = factorial[i - 1] * i;
            }
    
            for (const string &s: m) {
                std::vector<int> cnt(10);
    
                for (char c: s) {
                    cnt[c - '0']++;
                }
    
                long long tot = (n - cnt[0]) * factorial[n - 1];
    
                for (int x: cnt) {
                    tot /= factorial[x];
                }
    
                ans += tot;
            }
    
            return ans;
        }
    };