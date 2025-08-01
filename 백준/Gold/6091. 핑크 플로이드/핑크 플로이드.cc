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
vector<int> parent;    
vector<vector<int>> ans;
int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if (px > py)
        swap(px, py);
    parent[py] = px;
    ans[x].push_back(y);
    ans[y].push_back(x);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, pi>> v;
    parent.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1, x; j <= n; j++) {
            cin >> x;
            v.push_back({ x, {i,j} });
        }
        parent[i] = i;
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int cnt = n - 1;
    for (int i = 0; i < v.size(), cnt > 0; i++) {
        auto cur = v[i];
        int w = cur.X;
        int x = cur.Y.X;
        int y = cur.Y.Y;

        if (find(x) != find(y)) {
            cnt--;
            merge(x, y);
        }
    }
    
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i].size() << " ";
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}