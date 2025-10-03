#include <iostream>
using namespace std;
signed main() {
    int n, w;
    cin >> n >> w;
    
    int ans = 0;
    ans += n * 10;
    if (n >= 3) ans += 20;
    if (n == 5) ans += 50;
    if (w > 1000) ans -= 15;
    if (ans < 0) ans = 0;
    cout << ans << '\n';
}