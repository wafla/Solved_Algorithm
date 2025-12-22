#include <iostream>
#include <math.h>
#define int long long
using namespace std;
int solve(int n) {
    if (n == 0) return 0;
    return solve(floor(n / 2)) + n;
}
signed main() {
    int n;
    cin >> n;
    cout << solve(n);
}