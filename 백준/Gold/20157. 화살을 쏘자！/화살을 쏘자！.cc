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

    int n;
    cin >> n;

    map<pi, int> M;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;

        M[{x, y}]++;
    }

    int ans = 0;
    for (auto i : M) {
        if (i.Y > ans) ans = i.Y;
    }
    cout << ans << '\n';
}
