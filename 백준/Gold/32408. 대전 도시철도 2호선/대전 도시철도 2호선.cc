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
int n;
int visited[100001] = { 0 };
int parent[100001] = { 0 };
vector<vector<int>> v(100001);
int dfs(int idx) {
    int size = 1;
    visited[idx] = 1;
    for (auto nx : v[idx]) {
        if (!visited[nx]) size += dfs(nx);
    }
    return size;
}
void find(int x, int p) {
    parent[x] = p;
    for (auto nx : v[x]) {
        if (nx == p) continue;
        find(nx, x);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    find(1, 0);

    int cur = n;
    while (cur != 0) {
        visited[cur] = INF;
        cur = parent[cur];
    }

    vector<int> sizes;
    for (int i = 1; i <= n; i++) {
        if (visited[i] != INF) continue;
        for (auto nx : v[i]) {
            if (visited[nx]) continue;

            int size = dfs(nx);
            sizes.push_back(size);
        }
    }

    int ans = 0, sum = 0;
    for (auto i : sizes) {
        ans += sum * i;
        sum += i;
    }
    cout << ans << '\n';
}