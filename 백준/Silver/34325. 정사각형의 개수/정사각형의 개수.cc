#include <iostream>
using namespace std;
long long MOD = 1000000007;
long long dp[1000001] = { 0 };
long long modpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    long long n, k;
    cin >> n >> k;

    dp[1] = 1, dp[2] = 4;
    long long x = 1;
    for (long long i = 3; i <= n; i++) {
        if (i % 2) dp[i] = i * i + 4 * x * x;
        else {
            dp[i] = i * i + 4 * x * (x + 1);
            x++;
        }
        dp[i] %= MOD;
    }

    long long ans = 0;
    for (long long i = n; i >= 1; i--) {
        ans = (ans + dp[i] * modpow(k, n + 1 - i)) % MOD;
    }
    cout << ans << '\n';
}