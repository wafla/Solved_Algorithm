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
int arr[202][2] = { 0 };
int dp[202][202][3] = { 0 };
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n + 1; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    dp[1][1][0] = arr[1][1];
    dp[1][1][1] = arr[1][0];
    dp[1][0][2] = arr[1][0] + arr[1][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j > 0) {
                dp[i][j][0] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + arr[i][1];
                dp[i][j][1] = max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][0];
            }
            if (i != j) {
                dp[i][j][2] = max(dp[i - 1][j][0], max(dp[i - 1][j][1], dp[i - 1][j][2])) + arr[i][0] + arr[i][1];
            }
        }
    }

    cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2])) << '\n';
}
// 참고 : https://lyzqm.blogspot.com/2017/06/10476.html