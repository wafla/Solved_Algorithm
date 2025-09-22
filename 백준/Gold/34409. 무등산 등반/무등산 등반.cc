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
int n, m;
int sx, sy;
int a, b, c;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
vector<vector<int>> v, dist;
void solve() {
    priority_queue<T, vector<T>, greater<T>> PQ;
    sx--, sy--;
    PQ.push({ 0, {sx,sy} });
    dist[sx][sy] = 0;
    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        int x = cur.Y.X;
        int y = cur.Y.Y;
        int num = cur.X;
        if (num > dist[x][y])
            continue;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (v[x][y] == v[nx][ny]) {
                if (dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    PQ.push({ dist[nx][ny], {nx,ny} });
                }
            }
            else if (v[x][y] < v[nx][ny] && v[x][y] + c >= v[nx][ny]) {
                if (dist[x][y] + (v[nx][ny] - v[x][y]) * a < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + (v[nx][ny] - v[x][y]) * a;
                    PQ.push({ dist[nx][ny], {nx,ny} });
                }
            }
            else if (v[x][y] > v[nx][ny] && v[x][y] - c <= v[nx][ny]) {
                if (dist[x][y] + (v[x][y] - v[nx][ny]) * b < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + (v[x][y] - v[nx][ny]) * b;
                    PQ.push({ dist[nx][ny], {nx,ny} });
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    cin >> sx >> sy;
    cin >> a >> b >> c;
    
    v.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m, INF));
    int maxx = 0;
    pi top = { 0,0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (maxx < v[i][j]) {
                maxx = v[i][j];
                top = { i,j };
            }
        }
    }
    solve();
    if (dist[top.X][top.Y] == INF)
        cout << -1 << '\n';
    else
        cout << dist[top.X][top.Y] << '\n';
}