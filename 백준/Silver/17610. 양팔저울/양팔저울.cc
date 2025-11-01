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
set<int> S;
vector<int> v;
int k, sum = 0;
void solve(int idx, int sum) {
    if (idx == k) {
        if (sum >= 0) S.insert(sum);
        return;
    }
    solve(idx + 1, sum);
    if (idx > -1) {
        solve(idx + 1, sum + v[idx]);
        solve(idx + 1, sum - v[idx]);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> k;
    v.resize(k);
    for (auto& i : v) {
        cin >> i;
        sum += i;
    }

    solve(-1, 0);
    S.erase(0);
    cout << sum - S.size() << '\n';
}