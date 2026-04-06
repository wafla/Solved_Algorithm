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

    int n, q, x, num;
    cin >> n >> q;

    set<int> S;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == 1) S.insert(i);
    }

    int idx = 1;
    for (int i = 0; i < q; i++) {
        cin >> x;

        if (x == 1) {
            cin >> num;

            if (S.count(num))
                S.erase(num);
            else
                S.insert(num);
        }
        else if (x == 2) {
            cin >> num;

            idx = (idx + num) % n;
            if (idx == 0) idx = n;
        }
        else if (x == 3) {
            if (S.size()) {
                if (S.count(idx)) {
                    cout << 0 << '\n';
                }
                else {
                    S.insert(idx);
                    
                    auto it = S.find(idx);
                    it = next(it);

                    if (it == S.end()) {
                        it = S.begin();
                    }
                    
                    cout << (*it - idx + n) % n << '\n';

                    S.erase(idx);
                }
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}
