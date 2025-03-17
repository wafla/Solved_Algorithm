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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> dp(n + 1, vector<pi>(1, { 0,0 }));
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int a, b;
            cin >> a >> b;
            if (dp[a].size() == 1) {
                dp[a].emplace_back(i, b);
            }
            else {
                int prev_idx = dp[a][dp[a].size() - 1].X;
                if (prev_idx + 1 == i) {
                    int tmp = max(dp[a][dp[a].size() - 1].Y, dp[a][dp[a].size() - 2].Y + b);
                    dp[a].emplace_back(i, tmp);
                }
                else {
                    dp[a].emplace_back(i, dp[a][dp[a].size() - 1].Y + b);
                }
            }
        }
        if (i == m) {
            for (int j = 1; j <= n; j++) {
                ans += dp[j].back().Y;
            }
        }
    }
    cout << ans << '\n';
}