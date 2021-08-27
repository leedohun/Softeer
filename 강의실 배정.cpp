#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector <pair<int, int>> v;

int main(int argc, char** argv) {
        int ans = 0;

        int N; cin>> N;
        for(int i = 0; i < N; i++){
                int S, F; cin >> S>> F;

                v.push_back({F, S});
        }
        
        sort(v.begin(), v.end());

        int last_time = 0;
        for(int i = 0; i < N; i++){
                if(last_time <= v[i].second){
                        last_time = v[i].first;
                        ans++;
                }
        }
        
        cout << ans << "\n";

        return 0;
}
