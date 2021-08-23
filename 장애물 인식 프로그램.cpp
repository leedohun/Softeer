#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct P{
        int x; int y;
};

int N;

string map[26];
bool visit[25][25] = {false,};

int block_cnt = 0;
vector <int> block_size;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int BFS(int a, int b){
        int cnt = 1;

        queue <P> que;
        que.push({a, b});
        visit[a][b] = true;

        while(!que.empty()){
                int cur_x = que.front().x;
                int cur_y = que.front().y;

                que.pop();

                for(int i =0; i < 4; i++){
                        int xx = cur_x + dx[i];
                        int yy = cur_y + dy[i];

                        if(xx < 0 || yy < 0 || N <= xx || N <= yy){
                                continue;
                        }
                        
                        if(!visit[xx][yy] && map[xx][yy] == '1'){
                                visit[xx][yy] = true;
                                que.push({xx, yy});
                                cnt++;
                        }
                }
        }
        return cnt;
}

int main(int argc, char** argv) {
        cin >> N;
        for(int i = 0; i < N; i++){
                cin >> map[i];
        }

        for(int i = 0; i < N; i++){
                for(int j = 0; j< N ; j++){
                        if(!visit[i][j] && map[i][j] == '1'){
                                block_cnt++;
                                block_size.push_back(BFS(i, j));
                        }
                }
        }

        sort(block_size.begin(), block_size.end());
        cout << block_cnt << "\n";
        for(int i = 0; i < block_size.size(); i++){
                cout << block_size[i] << "\n";
        }

        return 0;
}
