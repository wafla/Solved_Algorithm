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
int llpow(int a, int e) {
    int r = 1;
    while (e--) {
        r = (r * a) % MOD;
    }
    return r;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int a = llpow(26, n); // E - 짝수 개수 O - 홀수 개수
    int b = llpow(22, n); // (E + O) + (E - O) = 2E = (전체) + (짝수)  // E = (전체 + 짝수) / 2
    int ans = ((a + b) % MOD) * 500000004 % MOD; // 모듈러에서는 나눗셈 대신 역원을 곱해야 한다. 2 * inv = 1 mod MOD
    cout << ans << '\n';
}