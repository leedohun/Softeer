#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int k; int x; int y;
};

int N, K;
vector <P> v;
int ans = 9876543;
set <int> s;

vector <int> breakPoint;

bool cmp(const P& a, const P& b) { //절대값으로 정렬을 통해서 bfs탐색의 횟수를 줄일 수 있다.
    if (a.k < b.k) return true;
    else if (a.k == b.k) {
        if (abs(a.x) < abs(b.x)) return true;
        else if (abs(a.y) == abs(b.y)) {
            if (abs(a.y) < abs(b.y))
                return true;
        }
    }
    return false;
}

void bfs(int hx, int hy, int lx, int ly, int a, int cnt) {
    int tmp = abs(hx - lx) * abs(hy - ly);

    if (cnt == K) {
        ans = min(tmp, ans);
        return;
    }

    if(ans == 0 || ans <= tmp) { //현재 구하고자 하는 넓이가 구했던(ans) 넓이보다 크거나 ans == 0이면 그냥 break;
        return;
    }

    for (int i = a; i < N; i++) {
        if (s.find(v[i].k) == s.end()) {
            for(int j = 0; j < K - 1; j++) {
                if(breakPoint[j] < i && s.find(v[breakPoint[j]].k) == s.end()) { //정렬된 점에서 앞에 있는 점을 선택하지 않으면 구할 필요가 없다.
                    return;
                }
            }
            s.insert(v[i].k);
            bfs(max(hx, v[i].x), max(hy, v[i].y), min(lx, v[i].x), min(ly, v[i].y), i + 1, cnt + 1);
            s.erase(v[i].k);
        }
    }
}

void solved() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x, y, k; cin >> x >> y >> k;

        v.push_back({ k, x, y });
    }
    sort(v.begin(), v.end(), cmp);

    for(int i = 1; i < N; i++) {
        if(v[i-1].k != v[i].k) {
            breakPoint.push_back(i - 1);
        }
    }

    bfs(-1001, -1001, 1001, 1001, 0, 0);
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
