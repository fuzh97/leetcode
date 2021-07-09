/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;
    class Solution {
    public:
        int countPrimes(int n) {
            vector<int> isPrime(n, 1);
            int ans = 0;
            for (int i = 2; i < n; i++) {
                if (isPrime[i] == 1) {
                    ans++;
                    if ((long long)i * i < n) {
                        for (int j = i * i; j < n; j += i) {
                            isPrime[j] = 0;
                        }
                    }
                }
            }
            return ans;
        }
    };
// @lc code=end
