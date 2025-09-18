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
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> arr(n, vector<vector<int>>(m, vector<int>(3)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j][0];
            arr[i][j][1] = arr[i][j][2] = arr[i][j][0];
        }
    }
    
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INF)));
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
            dp[0][j][k] = arr[0][j][k];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int left = j - 1, right = j + 1;
            for (int k = 0; k < 3; k++) {
                if (k == 0) { // 이전에 왼쪽에서 가져옴
                    if (left >= 0) {
                        dp[i][j][k] = min(dp[i - 1][left][1], dp[i - 1][left][2]) + arr[i][j][k];
                    }
                }
                else if (k == 1) { // 이전에 위에서 가져옴
                    dp[i][j][k] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j][k];
                }
                else if (k == 2) { // 이전에 오른쪽에서 가져옴
                    if (right < m) {
                        dp[i][j][k] = min(dp[i - 1][right][0], dp[i - 1][right][1]) + arr[i][j][k];
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
            ans = min(ans, dp[n - 1][j][k]);
        }
    }
    cout << ans << '\n';
}