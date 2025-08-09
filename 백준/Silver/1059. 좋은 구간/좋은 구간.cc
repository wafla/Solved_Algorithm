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

    int L;
    cin >> L;
    set<int> S;
    for (int i = 0, x; i < L; i++) {
        cin >> x;
        S.insert(x);
    }
    int n;
    cin >> n;
    if (S.count(n)) {
        cout << 0 << '\n';
    }
    else {
        int left = 0, right = 0;
        int left_idx = n - 1, right_idx = n + 1;
        while (!S.count(left_idx) && left_idx > 0) {
            left++;
            left_idx--;
        }
        while (!S.count(right_idx) && right_idx < 1001) {
            right++;
            right_idx++;
        }
        int ans = left + right + left * right;
        cout << ans << '\n';
    }
}