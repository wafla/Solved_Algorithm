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

    int n, m, d, e;
    cin >> n >> m >> d >> e;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<vector<pi>> arr(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[x].push_back({ z,y });
        arr[y].push_back({ z,x });
    }

    vector<int> arr1(n + 1), arr2(n + 1);
    fill(arr1.begin(), arr1.end(), INF);
    fill(arr2.begin(), arr2.end(), INF);

    priority_queue<int> PQ;
    PQ.push(1);
    arr1[1] = 0;
    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        for (int i = 0; i < arr[cur].size(); i++) {
            int nw = arr[cur][i].X;
            int nx = arr[cur][i].Y;
            int nh = v[nx];
            if (v[cur] < nh) {
                if (arr1[nx] > arr1[cur] + nw) {
                    arr1[nx] = arr1[cur] + nw;
                    PQ.push(nx);
                }
            }
        }
    }

    PQ.push(n);
    arr2[n] = 0;
    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        for (int i = 0; i < arr[cur].size(); i++) {
            int nw = arr[cur][i].X;
            int nx = arr[cur][i].Y;
            int nh = v[nx];
            if (v[cur] < nh) {
                if (arr2[nx] > arr2[cur] + nw) {
                    arr2[nx] = arr2[cur] + nw;
                    PQ.push(nx);
                }
            }
        }
    }

    int ans = -INF;
    for (int i = 2; i < n; i++) {
        if (arr1[i] == INF || arr2[i] == INF)
            continue;
        ans = max(ans, v[i] * e - (arr1[i] + arr2[i]) * d);
    }

    if (ans == -INF)
        cout << "Impossible\n";
    else
        cout << ans << '\n';
}