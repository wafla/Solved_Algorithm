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
    vector<vector<pi>> v(n + 1);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int a, b;
            cin >> a >> b;
            v[a].emplace_back(i, b);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        unordered_map<int, pi> dp;
        for (int j = 0; j < v[i].size(); j++) {
            int idx = v[i][j].X;
            int num = v[i][j].Y;
            if (j == 0) {
                dp[idx].X = 0; // 항상 배식하지 않음
                dp[idx].Y = num; // 항상 배식함
            }
            else {
                int prev_idx = v[i][j - 1].X;
                dp[idx].X = max(dp[prev_idx].X, dp[prev_idx].Y);
                if (prev_idx + 1 == idx) {
                    dp[idx].Y = dp[prev_idx].X + num;
                }
                else {
                    dp[idx].Y = max(dp[prev_idx].X, dp[prev_idx].Y) + num;
                }
            }
        }
        if (v[i].size()) {
            int last_idx = v[i][v[i].size() - 1].X;
            ans += max(dp[last_idx].X, dp[last_idx].Y);
        }
    }
    cout << ans << '\n';
}