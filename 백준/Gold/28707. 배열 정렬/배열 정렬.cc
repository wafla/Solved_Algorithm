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

    int n, m;
    cin >> n;

    vector<int> arr(n);
    for (auto& i : arr)
        cin >> i;

    cin >> m;
    vector<pair<int, pi>> v(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = { c, {a, b} };
    }

    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end());

    map<vector<int>, int> dist;
    dist[arr2] = 0;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> PQ;
    PQ.push({ 0, arr2 });

    while (!PQ.empty()) {
        auto [cost, cur] = PQ.top();
        PQ.pop();

        if (cost > dist[cur])
            continue;

        if (cur == arr) {
            cout << cost << '\n';
            return 0;
        }

        for (int i = 0; i < m; i++) {
            int a = v[i].Y.X - 1;
            int b = v[i].Y.Y - 1;
            int c = v[i].X;

            vector<int> nxt = cur;
            swap(nxt[a], nxt[b]);

            int ncost = cost + c;

            if (!dist.count(nxt) || ncost < dist[nxt]) {
                dist[nxt] = ncost;
                PQ.push({ncost, nxt});
            }
        }
    }

    cout << -1 << '\n';
}