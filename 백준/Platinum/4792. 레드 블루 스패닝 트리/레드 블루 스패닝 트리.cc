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
int arr[1001] = { 0 };
int find(int x) {
	if (x == arr[x])
		return x;
	return arr[x] = find(arr[x]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a < b)
		swap(a, b);
	arr[a] = b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	while (1) {
		int n, m, k;
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0)
			break;

		vector<T> v(m);
		for (int i = 0; i < m; i++) {
			char c;
			int f, t;
			cin >> c >> f >> t;
			if (c == 'B') {
				v[i] = { 0,{f,t} };
			}
			else {
				v[i] = { 1,{f,t} };
			}
		}

		int cnt = 0;
		iota(arr + 1, arr + n + 1, 1);
		sort(v.begin(), v.end());
		int b_max = 0;
		for (int i = 0; i < m; i++) {
			int c = v[i].X;
			int a = v[i].Y.X;
			int b = v[i].Y.Y;
			if (find(a) == find(b)) {
				continue;
			}
			else {
				merge(a, b);
				if (c == 0)
					b_max++;
				cnt++;
			}
			if (cnt == n - 1)
				break;
		}

		cnt = 0;
		iota(arr + 1, arr + n + 1, 1);
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int b_min = 0;
		for (int i = 0; i < m; i++) {
			int c = v[i].X;
			int a = v[i].Y.X;
			int b = v[i].Y.Y;
			if (find(a) == find(b)) {
				continue;
			}
			else {
				merge(a, b);
				if (c == 0)
					b_min++;
				cnt++;
			}
			if (cnt == n - 1)
				break;
		}

		if (b_min <= k && k <= b_max)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}
// 참고 : https://everenew.tistory.com/176