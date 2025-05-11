#include <iostream>
#include <map>
#define int long long
#define X first
#define Y second
#define pi pair<int, int>
using namespace std;
int dp[102][102] = { 0 };
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m; 
    cin >> n >> m;
    int t;
    cin >> t;
    map<pair<pi, pi>, int> M;
    for (int i = 0; i < t; i++) {
        pi a, b;
        cin >> a.X >> a.Y >> b.X >> b.Y;
        if (a > b) swap(a, b);
        M[{a, b}] = 1;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        if (M[{ {i - 1, 0}, { i,0 }}])
            dp[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = dp[0][i - 1];
        if (M[{ {0, i - 1}, { 0,i }}])
            dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = dp[j - 1][i];
            if (M[{ {j - 1, i}, { j,i }}])
                a = 0;
            int b = dp[j][i - 1];
            if (M[{ {j, i - 1}, { j,i }}])
                b = 0;
            dp[j][i] = a + b;
        }
    }

    cout << dp[n][m] << '\n';
}