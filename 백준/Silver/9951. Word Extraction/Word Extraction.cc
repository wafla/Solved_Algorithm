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
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
#define T pair<int, pi>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (1) {
        string s;
        getline(cin, s);
        if (s == "#")
            break;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
        set<string> S;
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                S.insert(tmp);
                tmp = "";
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
                tmp += s[i];
            else if (s[i] >= '0' && s[i] <= '9' && tmp != "")
                tmp += s[i];
        }
        if (tmp != "")
            S.insert(tmp);
        S.erase("");
        for (auto i : S)
            cout << i << '\n';
        cout << '\n';
    }
}