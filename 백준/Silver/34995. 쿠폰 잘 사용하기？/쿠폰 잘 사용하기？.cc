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

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '?') cout << '9';
            else cout << a[i];
        }
    }
    else if (a.size() == b.size()) {
        bool flag = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '?') {
                a[i] = '9';
            }
            if (!flag) {
                if (a[i] > b[i]) {
                    flag = 1;
                }
                else if (a[i] == b[i]) {
                    continue;
                }
                else {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
        cout << a << '\n';
    }
    else if (a.size() < b.size()) {
        cout << -1 << '\n';
    }
}