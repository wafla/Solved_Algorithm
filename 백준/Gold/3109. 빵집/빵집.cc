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
char arr[10002][502] = { 0 };
int v[10002][502] = { 0 };
int dx[3] = { -1,0,1 }, dy[3] = { 1,1,1 };
int r, c, ans = 0;
int solve(int x, int y) {
    v[x][y] = ans;
    if (y == c) {
        if (arr[x][y] == '.') {
            ans++;
            return 1;
        }
    }
    int flag = 0;
    for (int k = 0; k < 3; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx <= 0 || ny <= 0 || nx > r || ny > c)
            continue;
        if (arr[nx][ny] == '.' && v[nx][ny] == -1) {
            flag = solve(nx, ny);
            if (flag)
                break;
        }
    }
    if (flag)
        return 1;
    return 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> r >> c;
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
        }
    }
    memset(v, -1, sizeof(v));

    for (int i = 1; i <= r; i++) {
        if (arr[i][1] == '.') {
            solve(i, 1);
        }
    }

    cout << ans << '\n';
}