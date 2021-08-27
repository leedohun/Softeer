#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> v;

long long ans = 0;

int main(int argc, char** argv) {
        int W, N; cin >> W >> N;

        for(int i = 0; i < N; i++){
                int M, P; cin>> M >> P;
                v.push_back({P, M});
        }
        sort(v.begin(), v.end());

        int i = v.size() - 1;
        while(W){
                if(W - v[i].second >= 0){
                        W -= v[i].second;
                        ans += v[i].first * v[i].second;
                }
                else{
                        ans += v[i].first * W;
                        W = 0;
                }
                i--;
        }

        cout << ans << "\n";

        return 0;
}
