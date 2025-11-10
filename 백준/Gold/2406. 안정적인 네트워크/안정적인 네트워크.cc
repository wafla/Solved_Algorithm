#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <queue>
#define pi pair<int,int>
#define X first
#define Y second
#define T pair<int, pi>
using namespace std;
int n, m;
int parent[1001] = { 0 };
int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (py < px) swap(px, py);
    parent[py] = px;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    priority_queue<T, vector<T>, greater<T>> PQ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i == j) continue;
            if (i == 1 || j == 1 )continue;
            PQ.push({ x, {i, j}});
        }
    }

    int sum = 0;
    vector<pi> ans;
    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        int w = cur.X;
        int x = cur.Y.X;
        int y = cur.Y.Y;
        if (find(x) != find(y)) {
            sum += w;
            ans.push_back({x,y});
            merge(x, y);
        }
    }

    cout << sum << " " << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.X << " " << i.Y << '\n';
    }
}