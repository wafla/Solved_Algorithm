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

    int N, L;
    cin >> N >> L;

    vector<set<char>> v(L);
    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < L; j++) {
            v[j].insert(s[i][j]);
        }
    }

    string str = "", ans = "";
    for (int i = 0; i < L; i++) {
        str = s[0];
        for (auto j : v[i]) {
            str[i] = j;
            bool flag = 1;
            for (int k = 0; k < N; k++) {
                int cnt = 0;
                for (int p = 0; p < L; p++) {
                    if (s[k][p] != str[p]) {
                        cnt++;
                    }
                }
                if (cnt > 1) {
                    flag = 0;
                }
            }
            if (flag) {
                ans = str;
                break;
            }
        }
    }

    if (ans == "") {
        cout << "CALL FRIEND\n";
    }
    else {
        cout << ans << '\n';
    }
}