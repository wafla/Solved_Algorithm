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

    int n, m;
    cin >> n >> m;
    priority_queue<T, vector<T>, greater<T>> PQ;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        PQ.push({ z,{x,y} });
    }
    
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : find(parent[x]);
    };

    auto merge = [&](int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px < py) swap(px, py);
        parent[py] = px;
    };

    int ans = 0;
    while (n - 2) {
        auto cur = PQ.top();
        PQ.pop();
        int x = cur.Y.X;
        int y = cur.Y.Y;
        int w = cur.X;
        if (find(x) != find(y)) {
            merge(x, y);
            ans += w;
            n--;
        }
    }
    cout << ans << '\n';
}