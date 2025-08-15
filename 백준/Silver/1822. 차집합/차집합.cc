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

    int n, m;
    cin >> n >> m;
    set<int> a, b;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a.insert(x);
    }
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        b.insert(x);
    }
    int cnt = 0;
    set<int> ans;
    for (auto i : a) {
        if (!b.count(i)) ans.insert(i);
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << " ";
    cout << '\n';
}