#include <iostream>
#include <vector>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    vector<int> va(26), vb(26);
    for (int i = 0; i < a.size(); i++) {
        va[a[i] - 'A']++;
    }
    for (int i = 0; i < b.size(); i++) {
        vb[b[i] - 'A']++;
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (va[i] < vb[i]) flag = false;
    }
    if (!flag)
        cout << "NEED FIX\n";
    else
        cout << "OK\n";
}