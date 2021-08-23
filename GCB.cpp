#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y;
};

int N, M;

int ans = 0;

void solved() {    
    cin >> N >> M;
    vector <P> v(N);
    
    int tmp = 0;
    rep(i, N) {
        cin >> v[i].x >> v[i].y;
        v[i].x += tmp;
        tmp = v[i].x;
    }

    int h = 0;
    rep(i, M) {
        int x, y; cin >> x >> y;

        for (int j = h + 1; j <= h + x; j++) {
            for (int k = 0; k < v.size(); k++) {
                if (k == 0) {
                    if (0 < j && j <= v[k].x) {
                        ans = max(ans, y - v[k].y);
                    }
                }
                else {
                    if (v[k - 1].x < j && j <= v[k].x) {
                        ans = max(ans, y - v[k].y);
                    }
                }
            }
        }
        h += x;
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
