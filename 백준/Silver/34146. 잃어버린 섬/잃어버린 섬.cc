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
    int middle, other;
    if (m % 2)
        middle = n;
    else
        middle = 0;
    other = n * m - middle;

    map<int, int> M;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            M[x]++;
        }
    }

    for (auto i : M) {
        if (i.Y % 2) { // 홀수 개
            if (i.Y - 1 <= other) {
                other -= i.Y - 1;
                if (middle > 0) {
                    middle -= 1;
                }
                else {
                    cout << "NO\n";
                    return 0;
                }
            }
            else if (i.Y - 1 >= other) {
                middle -= i.Y - other;
                other = 0;
                if (middle < 0) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
        else { // 짝수 개
            if (i.Y <= other) {
                other -= i.Y;
            }
            else if (i.Y <= other + middle) {
                middle -= i.Y - other;
                other = 0;
            }
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}