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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string s;
        getline(cin, s);

        int sum = 0;
        bool flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '!') flag = 1;
            else if (s[i] >= '0' && s[i] <= '9') sum += s[i] - '0';
        }
        if (sum > 9) flag = 1;
        if (flag) cout << "!\n";
        else cout << sum << '\n';
    }
}