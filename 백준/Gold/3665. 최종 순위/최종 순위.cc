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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;

        vector<int> arr(n);
        for (auto& i : arr)
            cin >> i;

        vector<vector<bool>> v(n + 1, vector<bool>(n + 1, false));
        vector<int> inDegree(n + 1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                v[arr[i]][arr[j]] = true;
                inDegree[arr[j]]++;
            }
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if (v[a][b]) {
                v[a][b] = false;
                v[b][a] = true;
                inDegree[a]++;
                inDegree[b]--;
            }
            else {
                v[a][b] = true;
                v[b][a] = false;
                inDegree[a]--;
                inDegree[b]++;
            }
        }

        queue<int> Q;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) Q.push(i);
        }

        vector<int> ans;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (Q.empty()) {
                flag = 1;
                break;
            }
            if (Q.size() > 1) {
                flag = 2;
            }

            int x = Q.front(); Q.pop();
            ans.push_back(x);

            for (int nx = 1; nx <= n; nx++) {
                if (v[x][nx]) {
                    inDegree[nx]--;
                    if (inDegree[nx] == 0)
                        Q.push(nx);
                }
            }
        }

        if (flag == 0) {
            for (auto i : ans)
                cout << i << " ";
            cout << '\n';
        }
        else if (flag == 1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << "?\n";
        }
    }
}