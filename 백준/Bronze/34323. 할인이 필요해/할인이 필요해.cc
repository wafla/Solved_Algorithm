#include <iostream>
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    long long n, m, k, s;
    cin >> n >> m >> s;
    k = m + 1;
    long long a = k * s * (100 - n) / 100;
    long long b = (k - 1) * s;
    cout << (a < b ? a : b) << '\n';
}