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
int arr[52][52] = { 0 };
int n, k;
int ans = INF;

void check() {
    int x = 1, y = 0, dir = 0, cnt = 0; // dir :: 0-동, 1-남, 2-서, 3-북
    while (1) {
        if (ans != INF && cnt >= ans) break;
        if (x == n && y == n + 1) {
            if (ans > cnt) ans = cnt;
            break;
        }
        else if (x < 0 || x > n || y < 0 || y > n)
            break;
        if (dir == 0) {
            int nx = x;
            int ny = y + 1;
            if (arr[nx][ny] == 1)       dir = 1;
            else if (arr[nx][ny] == 3)  dir = 3;
            else if (arr[nx][ny] == 5)  dir = 0;
            else break;
            x = nx; 
            y = ny;
        }
        else if (dir == 1) {
            int nx = x + 1;
            int ny = y;
            if (arr[nx][ny] == 2)       dir = 0;
            else if (arr[nx][ny] == 3)  dir = 2;
            else if (arr[nx][ny] == 4)  dir = 1;
            else break;
            x = nx;
            y = ny;
        }
        else if (dir == 2) {
            int nx = x;
            int ny = y - 1;
            if (arr[nx][ny] == 0)        dir = 1;
            else if (arr[nx][ny] == 2)   dir = 3;
            else if (arr[nx][ny] == 5)   dir = 2;
            else break;
            x = nx;
            y = ny;
        }
        else if (dir == 3) {
            int nx = x - 1;
            int ny = y;
            if (arr[nx][ny] == 0)      dir = 0;
            else if (arr[nx][ny] == 1) dir = 2;
            else if (arr[nx][ny] == 4) dir = 3;
            else break;
            x = nx;
            y = ny;
        }
        cnt++;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;

    memset(arr, -1, sizeof(arr));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    arr[1][0] = 5;
    arr[n][n + 1] = 5;

    if (k == 0) {
        check();
    }
    else if (k == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int tmp = arr[i][j];
                for (int p = 0; p <= 5; p++) {
                    arr[i][j] = p;
                    if (tmp == arr[i][j]) continue;
                    check();
                }
                arr[i][j] = tmp;
            }
        }
    }

    if (ans == INF) cout << -1 << '\n';
    else cout << ans - 1 << '\n';
}
