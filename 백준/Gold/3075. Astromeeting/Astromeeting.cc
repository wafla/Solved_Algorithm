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

    int t;
    cin >> t;
    while (t--) {
        int n, p, q;
        cin >> n >> p >> q;
        
        vector<int> people(n);
        for (auto& i : people)
            cin >> i;

        vector<vector<int>> dp(p + 1, vector<int>(p + 1));
        for (int i = 0; i <= p; i++) {
            for (int j = 0; j <= p; j++) {
                if (i == j) continue;
                dp[i][j] = INF;
            }
        }

        for (int k = 0; k < q; k++) {
            int i, j, d;
            cin >> i >> j >> d;
            if (dp[i][j] > d) {
                dp[i][j] = d;
                dp[j][i] = d;
            }
        }

        for (int k = 1; k <= p; k++) {
            for (int i = 1; i <= p; i++) {
                for (int j = 1; j <= p; j++) {
                    if (dp[i][k] + dp[k][j] < dp[i][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }

        pi ans = { 101, INF };
        for (int k = 1; k <= p; k++) {
            int sum = 0;
            for (auto i : people) {
                if (dp[i][k] == INF) {
                    sum = INF;
                    break;
                }
                sum += dp[i][k] * dp[i][k];
            }
            if (sum < ans.Y) {
                ans = { k, sum };
            }
        }
        cout << ans.X << " " << ans.Y << '\n';
    }
}