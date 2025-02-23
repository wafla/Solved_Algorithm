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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
using namespace std;
int power(int b, int p) {
    int ans = 1;
    while (p) {
        if (p % 2) {
            ans = (ans * b) % MOD;
        }
        b = (b * b) % MOD;
        p /= 2;
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    if (n <= 1) 
        cout << 1 << '\n';
    else 
        cout << power(2, n - 1) << '\n';
}