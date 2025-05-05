class Solution {
public:
    int numTilings(int n) {
    const int MOD = 1e9 + 7;   
     if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<long long> dp(n + 1, 0);
    vector<long long> prefixSum(n + 1, 0); 

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    prefixSum[0] = 1;
    prefixSum[1] = 2; 
    prefixSum[2] = 4; 

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 2 * prefixSum[i - 3]) % MOD;
        prefixSum[i] = (prefixSum[i - 1] + dp[i]) % MOD;
    }

    return dp[n];
    }
};
