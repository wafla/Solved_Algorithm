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
    vector<vector<pi>> v(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }

    int node = 0, maxx = 0;
    function<void(int, int, int)> find_node = [&](int cur, int prv, int sum) {
        if (maxx < sum) {
            maxx = sum;
            node = cur;
        }
        for (int i = 0; i < v[cur].size(); i++) {
            int nxt = v[cur][i].X;
            int w = v[cur][i].Y;
            if (nxt == prv) continue;
            find_node(nxt, cur, sum + w);
        }
    };
    find_node(1, -1, 0);
    maxx = 0;
    find_node(node, -1, 0);
    cout << maxx << '\n';
}