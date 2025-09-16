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
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    priority_queue<T, vector<T>> PQ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= n; j++) {
            cin >> x;
            v[i][j] = x;
            PQ.push({ x, {i,j} });
        }
    }

    function<int(int)> find = [&](int x) {
        if (x == parent[x])
            return x;
        else return parent[x] = find(parent[x]);
    };

    function<void(int, int)> merge = [&](int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px > py)
            swap(px, py);
        parent[py] = px;
    };

    int sum = 0;
    int cnt = 0;
    vector<int> arr(n + 1, 0);
    vector<vector<int>> vv(n + 1);
    while (!PQ.empty()) {
        if (cnt == n - k)
            break;
        auto cur = PQ.top();
        PQ.pop();
        int num = cur.X;
        int x = cur.Y.X;
        int y = cur.Y.Y;
        if (find(x) != find(y)) {
            merge(x, y);
            sum += num;
            arr[x]++, arr[y]++;
            vv[x].push_back(y);
            vv[y].push_back(x);
            cnt++;
        }
    }

    cout << sum << '\n';
    while (cnt--) {
        int idx;
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 1) {
                idx = i;
                break;
            }
        }
        int idx2;
        for (int i = 0; i < vv[idx].size(); i++) {
            if (arr[vv[idx][i]] > 0) {
                idx2 = vv[idx][i];
                break;
            }
        }
        arr[idx]--, arr[idx2]--;
        cout << idx2 << " " << idx << '\n';
    }
}