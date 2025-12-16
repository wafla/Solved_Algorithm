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

    int l, n, k;
    cin >> l >> n >> k;
    vector<int> arr(n + 2);
    arr[0] = 0, arr[n + 1] = l;
    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];

    int maxx = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        int x = arr[i + 1] - arr[i];
        if (maxx < x)
            maxx = x;
    }

    int start = maxx, end = l, ans = l;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int cnt = 0;
        int tmp = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (arr[i] - tmp > mid) {
                cnt++;
                if (arr[i] - tmp == mid) tmp = arr[i];
                else tmp = arr[i - 1];
            }
        }
        if (cnt > k) {
            start = mid + 1;
        }
        else {
            ans = min(ans, mid);
            end = mid - 1;
        }
    }
    cout << ans << '\n';
}