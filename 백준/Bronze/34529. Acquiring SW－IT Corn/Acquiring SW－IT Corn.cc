#include <iostream>
using namespace std;
signed main() {
    int x, y, z;
    int u, v, w;
    cin >> x >> y >> z;
    cin >> u >> v >> w;
    cout << x * (u / 100) + y * (v / 50) + z * (w / 20) << '\n';
}