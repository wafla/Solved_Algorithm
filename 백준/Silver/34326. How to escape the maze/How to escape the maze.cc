#include <iostream>
#include <queue>
#define X first
#define Y second
#define pi pair<int, int>
using namespace std;
char arr[1002][1002] = { 0 };
int dx[8] = { -1, 0, 1, 0, -1, 0, 1, 0 }, dy[8] = { 0, 1, 0, -1, 0, 1, 0, -1 };
pi e;
int bfs(pair<pi, pi> s, int t) {
    queue<pair<pi, pi>> Q;
    Q.push(s);
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.X.X;
        int y = cur.X.Y;
        int dir = cur.Y.X;
        int cnt = cur.Y.Y;
        if (x == e.X && y == e.Y)
            return cnt;
        if (t == 0) { // 좌수법
            if (dir == 0) {
                for (int k = 3; k < 7; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
            else if (dir == 1) {
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
            else if (dir == 2) {
                for (int k = 1; k < 5; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
            else if (dir == 3) {
                for (int k = 2; k < 6; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
        }
        else if (t == 1) { // 우수법
            if (dir == 0) {
                for (int k = 5; k > 1; k--) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
            else if (dir == 1) {
                for (int k = 6; k > 2; k--) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
            else if (dir == 2) {
                for (int k = 3; k >= 0; k--) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
            else if (dir == 3) {
                for (int k = 4; k > 0; k--) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (arr[nx][ny] == '.') {
                        Q.push({ {nx,ny},{k % 4, cnt + 1} });
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    pair<pi, pi> s; // {x, y}, {방향, 카운트}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                if (i == 0)
                    s = { {i + 1,j}, {2, 0} };
                else if (i == n - 1)
                    s = { {i - 1,j}, {0, 0} };
                else if (j == 0)
                    s = { {i,j + 1}, {1, 0} };
                else if (j == m - 1)
                    s = { {i,j - 1}, {3, 0} };
                arr[i][j] = '.';
            }
            if (arr[i][j] == 'E') {
                e = { i,j };
                arr[i][j] = '.';
            }
        }
    }
    int left_cnt = bfs(s, 0);
    int right_cnt = bfs(s, 1);

    if (left_cnt == right_cnt)
        cout << "SAME\n";
    else if (left_cnt > right_cnt)
        cout << "RIGHT IS BEST\n";
    else
        cout << "LEFT IS BEST\n";
}