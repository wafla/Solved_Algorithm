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
int n;
int cost[16][16] = { 0 }, dp[16][1 << 16] = { 0 };
int solve(int idx, int visited) {
    int& ret = dp[idx][visited];

    if (ret != 0) return ret;

    if (visited == ((1 << n) - 1)) {
        if (cost[idx][0] != 0) 
            return cost[idx][0];
        return INF;
    }

    ret = INF;

    for (int i = 0; i < n; i++) {
        if (cost[idx][i] == 0 || (visited & (1 << i))) continue;

        ret = min(ret, cost[idx][i] + solve(i, visited | 1 << i));
    }

    return ret;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    cout << solve(0, 1) << '\n';
}