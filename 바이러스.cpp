#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    ll K, P, N; cin >> K >> P >> N;

    for (int i = 0; i < N; i++) {
        K *= P;
        K %= 1000000007;
    }

    cout << K;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
