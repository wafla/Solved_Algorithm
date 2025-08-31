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

    int a, b;
    cin >> a >> b;

    vector<int> dp(1001, -1);
    function<int(int, int)> gcd = [&](int a, int b) {
        while (b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    };
    function<int(int)> solve = [&](int x) {
        if (dp[x] != -1) return dp[x];
        
        bool chk = false;
        for (int i = x + 1; i <= b; i++) {
            if (gcd(x, i) == 1) {
                chk = true;
                if (solve(i) == 0) {
                    return dp[x] = 1;
                }
            }
        }
        if (!chk) return dp[x] = 0;
        return dp[x] = 0;
    };

    if (solve(a)) cout << "khj20006\n";
    else cout << "putdata\n";
}