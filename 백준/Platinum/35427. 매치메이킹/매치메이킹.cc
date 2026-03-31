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

    int q;
    cin >> q;

    priority_queue<T, vector<T>, greater<T>> PQ;
    map<int, int> M;
    set<pi> S;
    S.insert({ INF, 0 }), S.insert({ -INF, 0 });

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, b;
            cin >> a >> b;
            M[a] = b;
            S.insert({ b,a });

            auto it = S.find({ b,a });

            auto nx = next(it);
            if (nx != S.end() && nx->X != INF) {
                int num = nx->X - b;
                PQ.push({ num, {a, nx->Y} });
            }

            auto px = prev(it);
            if (px != S.begin() && px->X != -INF) {
                int num = b - px->X;
                PQ.push({ num, {a, px->Y} });
            }
        }
        else if (t == 2) {
            while (!PQ.empty()) {
                auto cur = PQ.top();
                PQ.pop();
                if (M[cur.Y.X] > 0 && M[cur.Y.Y] > 0) {
                    cout << cur.Y.X << " " << cur.Y.Y << '\n';
                    S.erase({ M[cur.Y.X], cur.Y.X });
                    S.erase({ M[cur.Y.Y], cur.Y.Y });
                    M[cur.Y.X] = 0; M[cur.Y.Y] = 0;
                    break;
                }
                else {
                    if (M[cur.Y.X] > 0) {
                        int a = cur.Y.X;
                        int b = M[cur.Y.X];

                        auto it = S.find({ b,a });

                        auto nx = next(it);
                        if (nx != S.end() && nx->X != INF) {
                            int num = nx->X - b;
                            PQ.push({ num, {a, nx->Y} });
                        }

                        auto px = prev(it);
                        if (px != S.begin() && px->X != -INF) {
                            int num = b - px->X;
                            PQ.push({ num, {a, px->Y} });
                        }
                    }
                    else if (M[cur.Y.Y] > 0) {
                        int a = cur.Y.Y;
                        int b = M[cur.Y.Y];

                        auto it = S.find({ b,a });

                        auto nx = next(it);
                        if (nx != S.end() && nx->X != INF) {
                            int num = nx->X - b;
                            PQ.push({ num, {a, nx->Y} });
                        }

                        auto px = prev(it);
                        if (px != S.begin() && px->X != -INF) {
                            int num = b - px->X;
                            PQ.push({ num, {a, px->Y} });
                        }
                    }
                }
            }
        }
    }
}
