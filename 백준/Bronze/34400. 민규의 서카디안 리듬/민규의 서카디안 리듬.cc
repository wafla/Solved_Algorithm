#include <iostream>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x % 25 > 16 && x % 25 < 25)
            cout << "OFFLINE\n";
        else
            cout << "ONLINE\n";
    }
}