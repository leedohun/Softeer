#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N, K;
string map;
bool visit[20005] = {0,};

int ans = 0;

int main(int argc, char** argv) {
        cin >> N >> K;
        cin >> map;

        for(int i = 0; i < N; i++){
                if(map[i] == 'P'){
                        int j = max(i - K, 0);

                        while(j <= i + K){
                                if(map[j] == 'H' && !visit[j]){
                                        visit[j] = true;
                                        ans++;
                                        break;
                                }
                                j++;
                        }
                }
        }

        cout << ans << "\n";

        return 0;
}
