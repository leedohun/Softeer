#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int cnt;
};

int R, W, r, w;
string m[51];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool v[51][51] = { false, };

int bfs() {
    queue <P> que;

    rep(i, R) rep(j, W) {
        if (m[i][j] == 'W') {
            v[i][j] = true;
            que.push({ i, j, 0 });
        }
        else if (m[i][j] == 'H') {
            r = i; w = j;
        }
    }

    int turn = 0;

    while (!que.empty()) {
        bool visit[51][51] = { false, };

        rep(i, R) rep(j, W) {
            if (m[i][j] == '*')
                visit[i][j] = true;
        }

        rep(i, R) rep(j, W) {
            if (visit[i][j]) {
                rep(k, 4) {
                    int x = dx[k] + i;
                    int y = dy[k] + j;

                    if (x < 0 || y < 0 || R <= x || W <= y) continue;

                    if (m[x][y] == '.') m[x][y] = '*';
                }
            }
        }

        while (!que.empty() && que.front().cnt == turn) {

            for (int i = 0; i < 4; i++) {
                int x = que.front().x + dx[i];
                int y = que.front().y + dy[i];

                if (x == r && y == w)
                    return que.front().cnt + 1;

                if (x < 0 || y < 0 || R <= x || W <= y) continue;

                if (!v[x][y] && (m[x][y] == '.' || (x == r && y == w))) {
                    v[x][y] = true;
                    que.push({ x, y, que.front().cnt + 1 });
                }
            }
            que.pop();
        }

        turn++;
    }

    return -1;
}

void solved() {
    cin >> R >> W;
    rep(i, R)
        cin >> m[i];

    int ans = bfs();

    if (ans == -1)
        cout << "FAIL";
    else
        cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
