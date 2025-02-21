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
map<int, int> prefix;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        prefix[x]++;
        prefix[y]--;
    }

    int sum = 0;
    int maxx = 0;
    int start = 0, end = 0, tmp = -1;
    for (auto i : prefix) {
        sum += i.Y;  
        if (sum > maxx) {
            start = i.X;
            tmp = i.X;
            maxx = sum;
        }
        if (tmp != -1 && sum < maxx) {
            end = i.X;
            tmp = -1;
        }
    }

    cout << maxx << '\n';
    cout << start << " " << end << '\n';
}