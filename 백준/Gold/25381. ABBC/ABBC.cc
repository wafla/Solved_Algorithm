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

    string s;
    cin >> s;
    
    int ans = 0, a = 0, b = 0, c = 0;

    queue<int> A, B;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            A.push(i);
        }
        else if (s[i] == 'B') {
            B.push(i);
        }
        else if (s[i] == 'C') {
            if (!B.empty() && B.front() < i) {
                B.pop();
                ans++;
            }
        }
    }

    while (!A.empty() && !B.empty()) {
        if (B.front() > A.front()) {
            ans++;
            A.pop(); B.pop();
        }
        else {
            B.pop();
        }
    }

    cout << ans << '\n';
}