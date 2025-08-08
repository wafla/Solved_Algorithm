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

    int n;
    cin >> n;
    set<int> S;
    vector<int> v(n);
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int tmp = 1;
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i == j && arr[i][j] != 0) {
                cout << -1 << '\n';
                return 0;
            }
            if (i != j && arr[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            if (arr[i][j] == -1)
                tmp++;
        }
        v[i] = tmp;
        S.insert(tmp);
    }
    if (S.size() != n)
        cout << -1 << '\n';
    else {
        if (n == 1) {
            if (arr[0][0] != 0)
                cout << -1 << '\n';
            else
                cout << 1 << '\n';
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (arr[i][j] != -arr[j][i]) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
}