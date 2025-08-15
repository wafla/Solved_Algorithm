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

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ans;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans));

    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << " ";
    cout << '\n';
}