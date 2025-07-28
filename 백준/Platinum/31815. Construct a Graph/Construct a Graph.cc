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
#define INF 1e18
#define LINF 9223372036854775807
#define MOD 998244353
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

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    int ans = n * (n - 1) / 2;
    vector<vector<bool>> check(n + 1, vector<bool>(n + 1, true));

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (j == i || j == k) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << -1 << '\n';
                    return 0;
                }
                if (dist[i][j] == dist[i][k] + dist[k][j]){
                    if (check[i][j]) {
                        check[i][j] = check[j][i] = false;
                        ans--;
                        continue;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (check[i][j])
                cout << i << " " << j << " " << dist[i][j] << '\n';
        }
    }
}
// 참고 : https://velog.io/@vkdldjvkdnj/boj31815