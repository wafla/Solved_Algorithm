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
#include <functional>
#include <utility>
#define X first
#define Y second
#define INF 1e18
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
#define T pair<int, pi>
#define pdi pair<double, int>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    vector<vector<int>> dp(k + 1, vector<int>(4, INF));
    dp[0][0] = 0;

    for (int e = 0; e <= k; e++) {
        for (int d = 0; d < 4; d++) {
            if (dp[e][d] == INF) continue;

            if (e + a <= k) {
                dp[e + a][(d + 1) % 4] = min(dp[e + a][(d + 1) % 4], dp[e][d] + 1);
            }

            if (e + b <= k) {
                dp[e + b][(d + 3) % 4] = min(dp[e + b][(d + 3) % 4], dp[e][d] + 1);
            }

            if (e + c <= k) {
                dp[e + c][(d + 2) % 4] = min(dp[e + c][(d + 2) % 4], dp[e][d] + 1);
            }
        }
    }

    if (dp[k][0] == INF) cout << -1 << '\n';
    else cout << dp[k][0] << '\n';
}