#include<iostream>
#include<vector>

using namespace std;

vector <int> a;
int tree[1000005] = {0,};

int N, K;

void update(int i, int num){
        while(i <= N){
                tree[i] += num;
                i += (i & -i);
        }
}

int BIT(int i){
        int ans = 0;
        while(0 < i){
                ans += tree[i];
                i -= (i & -i);
        }

        return ans;
}

int main(int argc, char** argv) {
        cin >> N >> K;
        for(int i = 1; i <= N; i++){
                int tmp; cin>> tmp;
                update(i, tmp);
        }

        for(int i = 0; i < K; i++){
                int A, B; cin >> A >> B;

                cout<<fixed;
                cout.precision(2);
                
                cout << (BIT(B) - BIT(A - 1)) / (double)(B - A + 1) << "\n";
        }
        return 0;
}
