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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
#define ti tuple<int, int, int>
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int i, j;
    cin >> i >> j;
    if (n == 3) {
        if (i == 2 && j == 2) {
            cout << 1 << '\n';
        }
        else {
            cout << 4 << '\n';
        }
    }
    else {
        if (n % 2 == 0) {
            cout << n * n / 2 << '\n';
        }
        else {
            if (i % 2 == j % 2) {
                cout << n * n / 2 + 1 << '\n';
            }
            else {
                cout << n * n / 2 << '\n';
            }
        }
    }
}