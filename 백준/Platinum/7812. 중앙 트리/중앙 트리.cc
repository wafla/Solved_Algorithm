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
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<vector<pi>> v(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            v[x].push_back({ y,w });
            v[y].push_back({ x,w });
        }

        vector<int> dist(n);
        vector<int> subtree_size(n);
        function<void(int, int, int)> dfs = [&](int cur, int prv, int sum) {
            dist[0] += sum;
            subtree_size[cur] = 1;
            for (auto i : v[cur]) {
                if (i.X == prv) continue;
                dfs(i.X, cur, sum + i.Y);
                subtree_size[cur] += subtree_size[i.X];
            }

        };
        dfs(0, -1, 0);

        // (-w) * subtree_size[v] + (+w) * (N - subtree_size[v]) = w * (N - 2 * subtree_size[v])
        function<void(int, int)> solve = [&](int cur, int prv) {
            for (auto i : v[cur]) {
                if (i.X == prv) continue;
                dist[i.X] = dist[cur] + (n - 2 * subtree_size[i.X]) * i.Y;
                solve(i.X, cur);
            }
        };
        solve(0, -1);

        int ans = INF;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dist[i]);
        }
        cout << ans << '\n';
    }
}
// 참고 : https://rebro.kr/90