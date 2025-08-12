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

    int n, k;
    cin >> n >> k;
    vector<int> sum(n + 1);
    map<int, int> M;

    int ans = 0;
    M[0] = 1;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        sum[i] = x + sum[i - 1];
        if (M[sum[i] - k]) {
            ans += M[sum[i] - k];
        }
        M[sum[i]]++;
    }
    cout << ans << '\n';
}