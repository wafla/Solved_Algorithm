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
int arr[100001] = { 0 };
int p[100001] = { 0 };
int find(int x) {
    if (x == p[x]) {
        return x;
    }
    return p[x] = find(p[x]);
}
void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (py > px) swap(px, py);
    p[py] = px;
    arr[px] += arr[py];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        int xx = find(x);
        int yy = find(y);
        if (xx == yy) {
            cout << arr[xx] << '\n';
        }
        else {
            merge(x, y);
            cout << arr[find(x)] << '\n';
        }
    }
}