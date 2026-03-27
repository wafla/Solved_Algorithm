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

    int n, sum = 0;
    cin >> n;

    vector<pi> v(n);
    for (auto& i : v) {
        cin >> i.X >> i.Y;
        sum += i.Y;
    }
    sort(v.begin(), v.end());

    int ans = v[0].X, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += v[i].Y;
        if (sum2 >= ceil(double(sum) / 2)) {
            ans = v[i].X;
            break;
        }
    }

    cout << ans << '\n';
}