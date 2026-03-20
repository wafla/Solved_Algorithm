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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pi> arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            arr.push_back({x, i});
        }
    }

    sort(arr.begin(), arr.end());

    int left = 0, right = 1;
    int minn = INF;
    set<int> total;
    total.insert(arr[left].Y);
    total.insert(arr[right].Y);
    vector<set<int>> checked(n);
    checked[arr[left].Y].insert(arr[left].X);
    checked[arr[right].Y].insert(arr[right].X);

    while (true) {
        if (total.size() < n) {
            right++;
            if (right >= n * m)
                break;
            total.insert(arr[right].Y);
            checked[arr[right].Y].insert(arr[right].X);
            continue;
        }
        else {
            if (arr[right].X - arr[left].X < minn) minn = arr[right].X - arr[left].X;
            checked[arr[left].Y].erase(arr[left].X);
            if (checked[arr[left].Y].size() == 0)
                total.erase(arr[left].Y);
            left++;
            if (left > right)
                break;
        }
    }

    cout << minn << '\n';
}