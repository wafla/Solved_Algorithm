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

    int h, n;
    cin >> h >> n;
    vector<pi> v(n), tmp;
    for (int i = 0; i < n; i++) {
        cin >> v[i].Y >> v[i].X;
    }
    tmp = v;
    sort(tmp.begin(), tmp.end());
    map<pi, int> M;
    int cnt = 1;
    for (auto i : tmp) {
        M[{i.X, i.Y}] = cnt++;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << M[{v[i].X, v[i].Y}] << " ";
    }
    cout << '\n';
}