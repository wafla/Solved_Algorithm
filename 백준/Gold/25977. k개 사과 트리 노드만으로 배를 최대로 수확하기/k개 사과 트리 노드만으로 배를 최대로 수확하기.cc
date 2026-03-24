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
bool visited[17][1 << 17];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> arr(n);
    for (auto& i : arr)
        cin >> i;

    pi ans = { 0, 0 };

    if (arr[0] == 0)
        ans = { 0,0 };
    else if (arr[0] == 1)
        ans = { 1,0 };
    else if (arr[0] == 2)
        ans = { 0,1 };

    queue<pair<pi, pi>> Q; // {idx, 방문한 곳}, {사과, 배}
    Q.push({ {0,1 << 0}, ans });
    visited[0][1 << 0] = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        int idx = cur.X.X;
        int mask = cur.X.Y;
        int ap = cur.Y.X;
        int pe = cur.Y.Y;

        if (ap > k)
            continue;

        if (pe > ans.Y)
            ans = { ap, pe };

        for (int i = 0; i < v[idx].size(); i++) {
            int nx = v[idx][i];
            int nmask = mask | (1 << nx);
            bool firstVisit = !(mask & (1 << nx));
            int nap = ap;
            int npe = pe;

            if (firstVisit) {
                if (arr[nx] == 1) nap++;
                else if (arr[nx] == 2) npe++;
            }

            if (!visited[nx][nmask]) {
                visited[nx][nmask] = true;
                Q.push({ {nx, nmask}, {nap, npe} });
            }
        }
    }

    cout << ans.Y << '\n';
}