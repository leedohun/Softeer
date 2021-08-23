#include<iostream>
#include<queue>

using namespace std;

struct P{
        int x; int y;
};

int N, M;
int ice_map[105][105] = {0,};

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool TocheckIce(){
        bool check = true;
        for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                        if(ice_map[i][j] == 1){
                                check = false;
                        }
                }
        }
        return check;
}

void BFS() {
        queue<P> que;
        bool visit[105][105] = {false,};

        que.push({0, 0});
        visit[0][0] = true;

        while(!que.empty()){
                int cur_x = que.front().x;
                int cur_y = que.front().y;

                que.pop();

                for(int i = 0; i < 4; i++){
                        int x = cur_x + dx[i];
                        int y = cur_y + dy[i];

                        if(x < 0 || y < 0 || N <= x || M <= y){
                                continue;
                        }

                        if(ice_map[x][y] != 0){
                                ice_map[x][y]++;
                                continue;
                        }

                        if(ice_map[x][y] == 0 && !visit[x][y]){
                                que.push({x, y});
                                visit[x][y] = true;
                        }
                }
        }
        return;
}

int ice_melt(){
        for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                        if(ice_map[i][j] == 2){
                                ice_map[i][j] = 1;
                        }else if(ice_map[i][j] > 2){
                                ice_map[i][j] = 0;
                        }
                }
        }
}

int main(int argc, char** argv) {
        cin >> N >> M;

        for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                        cin >> ice_map[i][j];
                }
        }

        int ans = 0;

        while(!TocheckIce()){
                ans++;
                BFS();
                ice_melt();
        }

        cout << ans << "\n";
        return 0;
}
