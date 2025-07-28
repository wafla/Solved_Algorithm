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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int idx = -1;
		for (int i = 0; i < s.size(); i += 2) {
			if (s[i] != '0') {
				idx = i;
			}
		}

		if (idx == -1) {
			cout << "YES\n";
			continue;
		}

		int flag = 0;
		for (int i = 1; i < idx - 2; i += 2) {
			if (s[i] == '-') {
				flag = 1;
				break;
			}
		}

		cout << (flag ? "NO\n" : "YES\n");
	}
}