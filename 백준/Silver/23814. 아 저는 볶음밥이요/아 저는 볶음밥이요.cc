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

    int d;
    cin >> d;
    int n, m, k;
    cin >> n >> m >> k;
    int a = d - n % d;
    int b = d - m % d;
    int tmp = n / d + m / d + k / d; // 그대로
    int tmp1 = (n + a) / d + (m + b) / d + (k - a - b) / d; // K를 N, M에 나눠줌
    int tmp2 = (n + a) / d + m / d + (k - a) / d; // K를 N에 나눠줌
    int tmp3 = n / d + (m + b) / d + (k - b) / d; // K를 M에 나눠줌
    int maxx = max(tmp, max(tmp1, max(tmp2, tmp3)));
    
    int ans = 0;
    if (maxx == tmp)
        ans = max(ans, k);
    if (maxx == tmp1)
        ans = max(ans, k - a - b);
    if (maxx == tmp2) 
        ans = max(ans, k - a);
    if (maxx == tmp3)
        ans = max(ans, k - b);
    cout << ans << '\n';
}