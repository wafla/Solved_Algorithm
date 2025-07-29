#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <tuple>
#include <numeric>
#include <bit>
#define X first
#define Y second
#define INF 1e18
#define LINF 9223372036854775807
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
#define T pair<int, pi>
using namespace std;
int countBits(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    
    vector<int> dp(1 << n, INF);
    dp[0] = 0;

    for (int i = 0; i < (1 << n); i++) {
        int person = countBits(i);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;
            int next = i | (1 << j);
            dp[next] = min(dp[next], dp[i] + v[person][j]);
        }
    }

    cout << dp[(1 << n) - 1] << '\n';
}