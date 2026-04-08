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
const int MAX = 2000;
int fact[MAX + 1] = { 0 }, ifact[MAX + 1] = { 0 };

int modPow(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x = x * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return x;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    ifact[MAX] = modPow(fact[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; i--) {
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto& i : v)
        cin >> i;

    init();

    int x = nCr(n, k);
    int y = modPow(2, k - 1);
    cout << (x * y) % MOD << '\n';
}
