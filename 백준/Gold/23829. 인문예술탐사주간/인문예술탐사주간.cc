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

    int n, q;
    cin >> n >> q;
    vector<int> v(n), sum(n);
    for (auto& i : v)
        cin >> i;
    sort(v.begin(), v.end());
    sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        sum[i] = v[i] + sum[i - 1];
    }
    
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        int idx = lower_bound(v.begin(), v.end(), x) - v.begin();

        int ans = 0;
        if (idx > 0) {
            ans += idx * x - sum[idx - 1];
        }
        if (idx < n) {
            ans += sum[n - 1] - (idx > 0 ? sum[idx - 1] : 0) - (n - idx) * x;
        }
        cout << ans << '\n';
    }
}