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

    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> arr(n - 1);
    for (auto& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());

    vector<int> dp(n + 1); // 부모 노드와 연결된 간선
    function<int(int)> dfs = [&](int x) {
        dp[x] = 1;
        for (auto i : v[x]) {
            if (!dp[i]) {
                dp[x] += dfs(i);
            }
        }
        return dp[x];
    };
    dfs(1);

    for (int i = 1; i <= n; i++)
        dp[i] = (n - dp[i]) * dp[i]; // 특정 간선을 지나는 정점 쌍의 수
    sort(dp.begin() + 1, dp.end(), greater<>());

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = (ans + dp[i] * arr[i - 1]) % MOD;
    }
    cout << ans << '\n';
}